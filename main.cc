#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <iostream>

int main() {
    char *outText;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();

    // Initialize tesseract-ocr with English
    if (api->Init(NULL, "eng")) {
        std::cerr << "Could not initialize tesseract.\n";
        exit(1);
    }

    // Set page segmentation mode to auto
    api->SetPageSegMode(tesseract::PSM_AUTO);

    // Open input image with leptonica library
    Pix *image = pixRead("/home/mertens/Desktop/Projects/visualverse/l.jpg");
    if (image == NULL) {
        std::cerr << "Could not read the image.\n";
        api->End();
        delete api;
        exit(1);
    }

    // Preprocess the image
    Pix *grayImage = pixConvertRGBToGray(image, 0.0, 0.0, 0.0);

    // Apply adaptive thresholding
    Pix *pixth = nullptr; // Threshold value image (optional, can be nullptr)
    Pix *binaryImage = nullptr; // Thresholded image
    if (pixOtsuAdaptiveThreshold(grayImage, 200, 200, 0, 0, 0.0, &pixth, &binaryImage) != 0) {
        std::cerr << "Error during adaptive thresholding.\n";
        pixDestroy(&image);
        pixDestroy(&grayImage);
        api->End();
        delete api;
        exit(1);
    }

    // Deskew the image (correct skew)
    Pix *deskewedImage = pixDeskew(binaryImage, 0);

    // Set the preprocessed image for OCR
    api->SetImage(deskewedImage);

    // Get OCR result
    outText = api->GetUTF8Text();
    if (outText == NULL) {
        std::cerr << "Could not get OCR result.\n";
    } else {
        std::cout << "OCR output:\n" << outText;
    }

    // Destroy used objects and release memory
    api->End();
    delete api;
    delete[] outText;
    pixDestroy(&image);
    pixDestroy(&grayImage);
    pixDestroy(&binaryImage);
    pixDestroy(&deskewedImage);
    pixDestroy(&pixth); // Clean up threshold value image

    return 0;
}
