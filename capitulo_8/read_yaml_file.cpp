
// Example 8-3. Using cv::FileStorage to read a .yml file
//
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  std::cout << "\nExample 8-3. Using cv::FileStorage to read a .yml file"
       << "\nCall:\n"
       << argv[0] << std::endl;
  
  cv::FileStorage fs2("test.yml", cv::FileStorage::READ);

  // first method: use (type) operator on FileNode.
  //
  int frameCount = (int)fs2["frameCount"];

  // second method: use cv::FileNode::operator >>
  //
  std::string date;
  fs2["calibrationDate"] >> date;

  cv::Mat cameraMatrix2, distCoeffs2;
  fs2["cameraMatrix"] >> cameraMatrix2;
  fs2["distCoeffs"] >> distCoeffs2;

  std::cout << "frameCount: "        << frameCount    << std::endl
       << "calibration date: "  << date          << std::endl
       << "camera matrix: "     << cameraMatrix2 << std::endl
       << "distortion coeffs: " << distCoeffs2   << std::endl;

  cv::FileNode features = fs2["features"];
  cv::FileNodeIterator it = features.begin(), it_end = features.end();
  int idx = 0;
  std::vector<uchar> lbpval;

  // iterate through a sequence using FileNodeIterator
  for( ; it != it_end; ++it, idx++ ) {

    std::cout << "feature #" << idx << ": ";
    std::cout << "x="   << (int)(*it)["x"]
         << ", y=" << (int)(*it)["y"]
         << ", lbp: (";

    // ( Note: easily read numerical arrays using FileNode >> std::vector. )
    //
    (*it)["lbp"] >> lbpval;
    for( int i = 0; i < (int)lbpval.size(); i++ )
      std::cout << " " << (int)lbpval[i];
    std::cout << ")" << std::endl;

  }

  fs2.release();

}