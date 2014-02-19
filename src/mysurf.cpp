#include <cstdarg>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "myplot.h"

namespace myplot {

    static const std::string default_style = "-";

    point3d::point3d(double x, double y, double z) : x(x), y(y), z(z) {
    }

    point3d::point3d(const point3d& other) : x(other.x), y(other.y), z(other.z) {
    }

    point3d::~point3d() {
    }
    
    double point3d::getx() const{
        return x;
    }
    
    double point3d::gety() const{
        return x;
    }
    
    double point3d::getz() const{
        return z;
    }

    std::ostream& operator<<(std::ostream& stream, point3d const& p) {
        stream << p.x << " " << p.y << " " << p.z;
        return stream;
    }

    surf_data::surf_data() : points(), style(default_style), iso_sample_size(0) {
    }
    
    surf_data::surf_data(std::string const& style) : points(), style(style), iso_sample_size(0) {
    }

    surf_data::surf_data(const surf_data& other) : points(other.points), style(other.style), iso_sample_size(0) {
    }

    surf_data::~surf_data() {
    }

    void surf_data::add_point(double x, double y, double z) {
        points.push_back(point3d(x, y, z));
        if(points.size() > 1 && points[points.size() - 1].getx() != points[points.size() - 2].getx()){
            iso_sample_size = points.size();
        }
    }

    int surf_data::size() const {
        return points.size();
    }

    bool surf_data::empty() const {
        return points.empty();
    }

    void surf_data::set_style(const std::string& s) {
        style = s;
    }

    char const* surf_data::get_style() const {
        return style.c_str();
    }
    
    surf_data surf_data::operator=(surf_data const& other) {
        return surf_data(other);
    }

    std::ostream& operator<<(std::ostream& stream, surf_data const& data) {
        for (int i = 0; i < data.size(); i++) {
            if(i != 0 && data.points[i].getx() != data.points[i-1].getx()){
                stream << std::endl;
            }
            stream << data.points[i];
            if (i < data.size() - 1)
                stream << std::endl;
        }
        return stream;
    }

    static void unpack_surfsty(const char *style, std::string *ret);
    
    void surf(surf_data_set data, const char* title) {
        
        if(data.empty()) {
            std::cerr << "Nothing to plot..." << std::endl;
            return;
        }
        
        std::ofstream plotfile("surfplot.cmd");
        plotfile << "set samples 30" << std::endl;
        plotfile << "set isosamples 30" << std::endl;
        plotfile << "set hidden3d back offset 1 trianglepattern 3 undefined 1 altdiagonal bentover" << std::endl;
        plotfile << "set title \"" << title << "\"" << std::endl;
        plotfile << "splot";
        
        for (int i = 0; i < data.size(); i++) {
            std::stringstream sstream;
            sstream << "data/data" << i << ".tmp";
            std::string filename = sstream.str();
            
            std::ofstream datafile(filename);
            datafile << data[i];
            datafile.close();
            
            std::string ret;
            unpack_surfsty(data[i].get_style(), &ret);
            plotfile << " \"" << filename << "\" " << ret;
            if(i != data.size() - 1){
                 plotfile << ",";
            } else {
                plotfile << std::endl;
            }
        }
//        plotfile << "replot" << std::endl;
        plotfile << "pause -1" << std::endl;
        plotfile.close();
        system("gnuplot surfplot.cmd");
    }
    
    static void unpack_surfsty(const char *style, std::string *ret) {
        *ret = (style[0] == '.') ? "with dots" :
                (style[0] == '+') ? "with points" : "with lines";
    }
}
