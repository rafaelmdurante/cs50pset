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
    /**
     * make a copy of the original image
     * because we need the original values
     */
    RGBTRIPLE imgBkp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgBkp[i][j].rgbtRed   = image[i][j].rgbtRed;
            imgBkp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            imgBkp[i][j].rgbtBlue  = image[i][j].rgbtBlue;
        }
    }
    // iterate over each row of the image
    for (int row = 0; row < height; row ++)
    {
        // iterate over each column of the image
        for (int column = 0; column < width; column++)
        {
            // for every pixel in the image
            // find the surrounding values
            int up, right, down, left;
            // the limit is the edge of the bitmap
            up    = row == 0            ? row    : row - 1;
            right = column == width - 1 ? column : column + 1;
            down  = row == height - 1   ? row    : row + 1;
            left  = column == 0         ? column : column - 1;
            // count the number of valid surrounding pixels for each pixel
            float surroundingPixels = 0;
            // sum the total value of RGB
            int tRed = 0,
                tGreen = 0,
                tBlue = 0;
            // iterate over each surrouding row
            for (int surRow = up; surRow <= down; surRow++)
            {
                // iterave over each surrounding column
                for (int surCol = left; surCol <= right; surCol++)
                {
                    // increase the counter
                    surroundingPixels++;
                    // add the value to each total based on the backup image values
                    tRed   += imgBkp[surRow][surCol].rgbtRed;
                    tGreen += imgBkp[surRow][surCol].rgbtGreen;
                    tBlue  += imgBkp[surRow][surCol].rgbtBlue;
                }
            }
            // change the image's pixel
            image[row][column].rgbtRed   = round((float) tRed / surroundingPixels);
            image[row][column].rgbtGreen = round((float) tGreen / surroundingPixels);
            image[row][column].rgbtBlue  = round((float) tBlue / surroundingPixels);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    /**
     * make a copy of the original image
     * because we need the original values
     */
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            copy[i][j] = image[i][j];

    // declare gX
    int gX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    // declare gY
    int gY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // iterate over each row in the image
    for (int row = 0; row < height; row++)
    {
        // iterate over each line in the image
        for (int col = 0; col < width; col++)
        {
            // store the total amount for each channel according to each g matrix
            int totGxR, totGxG, totGxB, totGyR, totGyG, totGyB;
            totGxR = totGxG = totGxB = totGyR = totGyG = totGyB = 0;

            // iterate over both matrixes to get new values
            for (int matrixRow = -1; matrixRow <= 1; matrixRow++)
            {
                for (int matrixCol = -1; matrixCol <= 1; matrixCol++)
                {
                    // determine the table delta row and col
                    // that is the 9 pixels surrouding the image[row][col] pixel
                    int dr = row + matrixRow;
                    int dc = col + matrixCol;
                    // set all channels to value zero if pixel is not valid
                    if (dr >= 0 && dr < height && dc >= 0 && dc < width)
                    {
                        // determine the gx index (in order to get the matrix weight)
                        int gxi = matrixRow + 1;
                        int gyi = matrixCol + 1;
                        // calculate the gx for each channel
                        totGxR += gX[gxi][gyi] * copy[dr][dc].rgbtRed;
                        totGxG += gX[gxi][gyi] * copy[dr][dc].rgbtGreen;
                        totGxB += gX[gxi][gyi] * copy[dr][dc].rgbtBlue;
                        // calculate the gy for each channel
                        totGyR += gY[gxi][gyi] * copy[dr][dc].rgbtRed;
                        totGyG += gY[gxi][gyi] * copy[dr][dc].rgbtGreen;
                        totGyB += gY[gxi][gyi] * copy[dr][dc].rgbtBlue;
                    }
                }
            }
            // save the new value for each channel
            int newRed, newGreen, newBlue;
            newRed   = round(sqrt(pow(totGxR, 2) + pow(totGyR, 2)));
            newGreen = round(sqrt(pow(totGxG, 2) + pow(totGyG, 2)));
            newBlue  = round(sqrt(pow(totGxB, 2) + pow(totGyB, 2)));
            // make sure max value is 255 and change the original pixel value
            image[row][col].rgbtRed   = newRed   > 255 ? 255 : newRed;
            image[row][col].rgbtGreen = newGreen > 255 ? 255 : newGreen;
            image[row][col].rgbtBlue  = newBlue  > 255 ? 255 : newBlue;
        }
    }
}
