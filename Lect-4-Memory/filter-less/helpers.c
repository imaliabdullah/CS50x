#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Sum the RGB values of the pixel, calculate the average of this
            // sum, and round it
            int sum = image[y][x].rgbtBlue + image[y][x].rgbtGreen +
                      image[y][x].rgbtRed;
            int average = round(sum / 3.0);

            // Set the RGB values of the pixel to be equal to the average
            image[y][x].rgbtBlue = average;
            image[y][x].rgbtGreen = average;
            image[y][x].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Declare RGB variables for the pixel
            int originalBlue = image[y][x].rgbtBlue;
            int originalGreen = image[y][x].rgbtGreen;
            int originalRed = image[y][x].rgbtRed;

            // Calculate the sepia versions of the pixel
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen +
                                  .131 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen +
                                   .168 * originalBlue);
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen +
                                 .189 * originalBlue);

            // Limit the sepia version to a maximum of 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Set the RGB values of the pixel to their sepia versions
            image[y][x].rgbtBlue = sepiaBlue;
            image[y][x].rgbtGreen = sepiaGreen;
            image[y][x].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        // Instead of checking all pixel columns, we will only check half, as by
        // swapping half of the pixels the other half will also be swapped
        for (int x = 0, temp; x < width / 2; x++)
        {
            // Swap the pixel in column x with the corresponding inverse column
            // pixel
            temp = image[y][x].rgbtBlue;
            image[y][x].rgbtBlue = image[y][width - 1 - x].rgbtBlue;
            image[y][width - 1 - x].rgbtBlue = temp;

            temp = image[y][x].rgbtGreen;
            image[y][x].rgbtGreen = image[y][width - 1 - x].rgbtGreen;
            image[y][width - 1 - x].rgbtGreen = temp;

            temp = image[y][x].rgbtRed;
            image[y][x].rgbtRed = image[y][width - 1 - x].rgbtRed;
            image[y][width - 1 - x].rgbtRed = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy the image because if not, blurring one pixel will affect the effect
    // on the next
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x].rgbtBlue = image[y][x].rgbtBlue;
            copy[y][x].rgbtGreen = image[y][x].rgbtGreen;
            copy[y][x].rgbtRed = image[y][x].rgbtRed;
        }
    }

    // Repeat the process for all pixels
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // Set variables for the sum of each RGB value, counter, and blur
            // radius
            int blueSum = 0, greenSum = 0, redSum = 0, c = 0;
            int r = 1;

            // Check each pixel and sum their RGB values according to the radius
            // Ex: radius 1, the sum will be done for all pixels up to 1
            // distance from the main pixel
            for (int row = y - r; row <= y + r; row++)
            {
                for (int column = x - r; column <= x + r; column++)
                {
                    if ((row >= 0 && column >= 0) &&
                        (row <= height - 1 && column <= width - 1))
                    {
                        blueSum += copy[row][column].rgbtBlue;
                        greenSum += copy[row][column].rgbtGreen;
                        redSum += copy[row][column].rgbtRed;
                        c++;
                    }
                }
            }

            // Take the average of the sum, according to how many pixels were
            // summed and rounding
            int averageBlue = round(blueSum * 1.0 / c);
            int averageGreen = round(greenSum * 1.0 / c);
            int averageRed = round(redSum * 1.0 / c);

            // Set the RGB values of the pixel to the RGB average of the
            // surrounding pixels
            image[y][x].rgbtBlue = averageBlue;
            image[y][x].rgbtGreen = averageGreen;
            image[y][x].rgbtRed = averageRed;
        }
    }
    return;
}
