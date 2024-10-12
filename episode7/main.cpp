#include "modules/cv/cv.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

// Function to process the frame
cv::Rect processFrame(cv::Mat& img, CMAKE_TUTORIAL::CV& cv, cv::Mat& med, cv::Mat& hsv, cv::Mat& mask, std::vector<std::vector<cv::Point>>& contours, std::vector<cv::Vec4i>& hierarchy) 
{
    // Apply median blur
    cv::medianBlur(img, med, 3);

    // Convert to HSV color space
    cv::cvtColor(med, hsv, cv::COLOR_BGR2HSV);

    // Define HSV range from cv object
    cv::Scalar lower(cv.hmin(), cv.smin(), cv.vmin());
    cv::Scalar upper(cv.hmax(), cv.smax(), cv.vmax());

    // Create binary mask
    cv::inRange(hsv, lower, upper, mask);

    // Find contours
    cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Find the target rectangle
    cv::Rect target_rect;
    for (size_t i = 0; i < contours.size(); i++) 
    {
        cv::Rect rect = cv::boundingRect(contours[i]);
        if (rect.area() > cv.getselect()) // Select based on the area
        {
            target_rect = rect;
            break; // Break early once you find the target
        }
    }

    return target_rect;
}

int main()
{
    // Video capture object
    cv::VideoCapture cap;
    
    // Path to the video file
    std::string path = "/Users/panyiming/Documents/code/CMAKE_TUTORIAL/episode7/kun.mp4";

    // Open the video file
    if (!cap.open(path)) 
    {
        std::cerr << "Error: Could not open video file at path: " << path << std::endl;
        return -1;
    }

    // Variables to hold frames and other processing results
    cv::Mat img, hsv, binary, med, mask;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    CMAKE_TUTORIAL::CV cv; // Instantiate cv object once, outside the loop

    while (true) 
    {
        // Capture frame
        cap >> img;
        if (img.empty()) 
        {
            std::cout << "End of video or failed to capture frame" << std::endl;
            break;
        }

        // Process the frame and find the target rectangle
        cv::Rect target_rect = processFrame(img, cv, med, hsv, mask, contours, hierarchy);

        // Draw the target rectangle on the image
        if (target_rect.area() > 0) 
        {
            cv::rectangle(img, target_rect, cv::Scalar(0, 255, 0), 5);
            cv::putText(img, "Brother's ball", cv::Point(target_rect.x, target_rect.y - 4),
                        cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 4, 8);
        }

        // Display images
        cv::imshow("Original", img);
        cv::imshow("Median Blurred", med);
        cv::imshow("HSV", hsv);
        cv::imshow("Mask", mask);

        // Exit on 'q' press
        int key = cv::waitKey(30);
        if (key == 'q') 
        {
            break;
        }
    }

    // Release resources
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
