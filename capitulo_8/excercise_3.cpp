/*
3. Create a program that reads in and displays an image.
a. Allow the user to select a rectangular region in the image by drawing a rectangle
with the mouse button held down, and highlight the region when the
mouse button is released. Be careful to save an image copy in memory so that
your drawing into the image does not destroy the original values there. The
next mouse click should start the process all over again from the original
image.
b. In a separate window, use the drawing functions to draw a graph in blue,
green, and red that represents how many pixels of each value were found in
the selected box. This is the color histogram of that color region. The x-axis
should be eight bins that represent pixel values falling within the ranges 0–31,
32–63,..., 223–255. The y-axis should be counts of the number of pixels that
were found in that bin range. Do this for each color channel, BGR.
*/

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class HistogramViewer
{
public:
    HistogramViewer(std::string);
    virtual ~HistogramViewer();
    
    void show();
    static void on_mouse_event(int event, int x, int y, int flags, void *userdata);
    
    typedef std::vector<std::vector<int>> histogram_bins;
    
private:
    cv::Mat image;
    cv::Mat display_image;
    
    cv::Rect mouse_drag_region;
    std::string filename;
    std::string image_window_name = "Image";
    std::string graph_window_name = "Color Histogram";
    
    histogram_bins calculate_bins(const cv::Mat&);
    void show_histogram();
    void draw_graph(const histogram_bins&);
    void add_graph_labels(cv::Mat&, int);
    void on_mouse_pressed(int event, int x, int y, int flags, void *userdata);
    void on_mouse_released(int event, int x, int y, int flags, void *userdata);
    void debug_output(std::ostream&, const histogram_bins&);
};

HistogramViewer::HistogramViewer(std::string filename) :
 filename(filename)
{
    cv::namedWindow(image_window_name);
    cv::setMouseCallback(image_window_name, HistogramViewer::on_mouse_event, this);
    
    cv::namedWindow(graph_window_name);
}

HistogramViewer::~HistogramViewer()
{
    cv::destroyWindow(graph_window_name);
    cv::destroyWindow(image_window_name);
}

void HistogramViewer::show()
{
    image = cv::imread(filename);
    display_image = image.clone();
    
    cv::imshow(image_window_name, display_image);
    
    cv::waitKey(0);
}

void HistogramViewer::show_histogram()
{
    cv::Mat color_histogram_region (image, mouse_drag_region);
    cv::rectangle(display_image, mouse_drag_region, cv::Scalar(175, 25, 225));
    cv::imshow(image_window_name, display_image);
    
    auto channel_data = calculate_bins(color_histogram_region);
    
    //debug_output(cout, bins);
    draw_graph(channel_data);
}

void HistogramViewer::draw_graph(const histogram_bins& channel_data)
{
    cv::Mat graph = cv::Mat::zeros(500, 500, CV_8UC(3));
    std::vector<cv::Scalar> bar_colors = { 
                                    cv::Scalar(200, 0, 0), 
                                    cv::Scalar(0, 200, 0), 
                                    cv::Scalar(0, 0, 200) 
                                };
    
    // find max value for y axis
    int max_count = 0;
    for (auto channel : channel_data)
    {
        for (auto pixel_count : channel)
        {
            if (pixel_count > max_count)
                max_count = pixel_count;
        }
    }
    
    // draw bars
    for (auto i = 0; i < 3; ++i)
    {
        const auto& current_channel = channel_data[i];
        const auto& current_bar_color = bar_colors[i];
        int offset_x = 0 + (5 * i);
        
        for (auto j = 0; j < 8; ++j)
        {
            const auto& bin_value = current_channel[j];
            double bar_scale = (double)bin_value / (double)max_count;
            auto bar_height = 300 * bar_scale;

            offset_x += 50;            
            cv::line(graph, 
                cv::Point(offset_x, 350 - bar_height), 
                cv::Point(offset_x, 350), 
                current_bar_color, 
                3);
        }
    }
    
    add_graph_labels(graph, max_count);
    
    cv::imshow(graph_window_name, graph);
}

void HistogramViewer::add_graph_labels(cv::Mat& graph, int max_count)
{
    cv::Scalar magenta(175, 25, 225);

    // x axis labels
    cv::putText(
            graph, 
            std::to_string(max_count), 
            cv::Point(0, 40), 
            cv::FONT_HERSHEY_PLAIN, 
            0.9, 
            magenta);
            
    cv::putText(
            graph, 
            std::to_string(max_count / 2), 
            cv::Point(0, 190), 
            cv::FONT_HERSHEY_PLAIN, 
            0.9, 
            magenta, 
            1);
            
    cv::putText(
            graph, 
            "0", 
            cv::Point(0, 350), 
            cv::FONT_HERSHEY_PLAIN, 
            0.9, 
            magenta, 
            1);
            
    // bin ranges / x axis labels
    for (auto i = 0; i < 8; ++i)
    {
        std::string bin_range;
        bin_range += std::to_string(i*32);
        bin_range += "-";
        bin_range += std::to_string((i+1)*32-1);
        cv::putText(
            graph, 
            bin_range, 
            cv::Point(25 + 50 * i, 400 + (i%2 * 25)), 
            cv::FONT_HERSHEY_PLAIN, 
            0.9, 
            magenta);
    }
    
    // axis descriptors
    cv::putText(
            graph, 
            "RGB Intensity", 
            cv::Point(200, 450), 
            cv::FONT_HERSHEY_PLAIN, 
            1.0, 
            magenta);
    
    cv::putText(
            graph, 
            "Pixel Count", 
            cv::Point(10, 10), 
            cv::FONT_HERSHEY_PLAIN, 
            1.0, 
            magenta);
}

void HistogramViewer::debug_output(std::ostream& os, const histogram_bins& channel_data)
{
    int i = 0;
    for (const auto& current_channel : channel_data)
    {
        os << "channel " << i << std::endl;
        int j = 0;
        for (const auto& value : current_channel)
        {
            os << j*32 << "-" << (j+1)*32-1 << ": " << value << std::endl;
            ++j;
        }
        ++i;
    }
}

HistogramViewer::histogram_bins HistogramViewer::calculate_bins(const cv::Mat& region)
{
    // TODO: get rid of magic numbers for channels, bin width & amount
    HistogramViewer::histogram_bins bins;
    bins.push_back(std::vector<int> (8, 0));
    bins.push_back(std::vector<int> (8, 0));
    bins.push_back(std::vector<int> (8, 0));
    
    for (cv::MatConstIterator_<cv::Vec3b> it = region.begin<cv::Vec3b>(); it != region.end<cv::Vec3b>(); ++it)
    {
        cv::Vec3b v = *it;
        auto b = v[0], g = v[1], r = v[2];
        
        auto b_bin = b / 32;
        auto g_bin = g / 32;
        auto r_bin = r / 32;
        
        bins[0][b_bin]++;
        bins[1][g_bin]++;
        bins[2][r_bin]++;
    }
    
    return bins;
}

void HistogramViewer::on_mouse_pressed(int event, int x, int y, int flags, void *userdata)
{
    image.copyTo(display_image);
    mouse_drag_region.x = x;
    mouse_drag_region.y = y;
}

void HistogramViewer::on_mouse_released(int event, int x, int y, int flags, void *userdata)
{    
    // TODO: this only supports topLeft->bottomRight dragging for now. exceptions! yay!
    mouse_drag_region.height = y - mouse_drag_region.y;
    mouse_drag_region.width = x - mouse_drag_region.x;
    
    std::cout << mouse_drag_region << std::endl;
    
    show_histogram();
}

void HistogramViewer::on_mouse_event(int event, int x, int y, int flags, void *userdata)
{
    HistogramViewer* p = static_cast<HistogramViewer*>(userdata);
    switch (event)
    {
    case cv::EVENT_LBUTTONDOWN:
        p->on_mouse_pressed(event, x, y, flags, userdata);
    break;
    case cv::EVENT_LBUTTONUP:
        p->on_mouse_released(event, x, y, flags, userdata);
    break;
    }
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "expects exactly one argument: filename" << std::endl;
    }
    
    HistogramViewer v { argv[1] };
    v.show();

    return 0;
}