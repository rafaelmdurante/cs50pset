#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // stores pixel to a variable called px
            RGBTRIPLE px = image[row][column];
            // calculates the average
            int average = round((px.rgbtRed + px.rgbtGreen + px.rgbtBlue) / 3.0);
            // change the original value to average
            image[row][column].rgbtRed = average;
            image[row][column].rgbtGreen = average;
            image[row][column].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // for each row
    for (int row = 0; row < height; row++)
    {
        // iterate over half of the image
        for (int column = 0; column < (width / 2); column++)
        {
            // store a backup of the original pixel
            RGBTRIPLE bkpPixel = image[row][column];
            // swap pixels
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = bkpPixel;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
