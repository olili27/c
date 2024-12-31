#include "helpers.h"
#include <math.h>

#define MODULO 256
#define MAX_BOX_COMPONENTS 9

typedef struct  
{
    int x;
    int y;
} POINT;

void add_pixel_value_indices(int height, int width, RGBTRIPLE image[height][width], int x, int y, POINT points[]);

RGBTRIPLE get_average(int height, int width, RGBTRIPLE image[height][width], POINT points[]);

void add_point(int height, int width, RGBTRIPLE image[height][width], POINT point, POINT points[], int current_index);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int avg = (int)(roundf(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue  = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int sepiaRed = (int)(roundf(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            sepiaRed %= MODULO;

            int sepiaGreen = (int)(roundf(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            sepiaGreen %= MODULO;

            int sepiaBlue = (int)(roundf(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));
            sepiaBlue %= MODULO;

            // Update pixel with sepia values
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, half = width / 2; j < half; j++)
        {
            // Swap pixels
            int current_last_index = width - 1 - j;
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][current_last_index];
            image[i][current_last_index] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    POINT points[MAX_BOX_COMPONENTS];

    for (int i = 0; i < MAX_BOX_COMPONENTS; i++)
    {
        points[i].x = -1;
        points[i].y = -1;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            add_pixel_value_indices(height, width, copy, i, j, points);
            image[i][j] = get_average(height, width, copy, points);
        }
    }
}

void add_pixel_value_indices(int height, int width, RGBTRIPLE image[height][width], int x, int y, POINT points[])
{
    POINT top_left_point = {.x = x - 1, .y = y - 1};
    add_point(height, width, image, top_left_point,points, 0);

    POINT top_point = {.x = x - 1, .y = y};
    add_point(height, width, image, top_point, points, 1);

    POINT top_right_point = {.x = x - 1, .y = y + 1};
    add_point(height, width, image, top_right_point, points, 2);

    POINT left_point = {.x = x, .y = y - 1};
    add_point(height, width, image, left_point, points, 3);

    POINT center_point = {.x = x, .y = y};
    add_point(height, width, image, center_point, points, 4);

    POINT right_point = {.x = x, .y = y + 1};
    add_point(height, width, image, right_point, points, 5);

    POINT bottom_left_point = {.x = x + 1, .y = y - 1};
    add_point(height, width, image, bottom_left_point, points, 6);

    POINT bottom_point = {.x = x + 1, .y = y};
    add_point(height, width, image, bottom_point, points, 7);

    POINT bottom_right_point = {.x = x + 1, .y = y + 1};
    add_point(height, width, image, bottom_right_point, points, 8);
}

RGBTRIPLE get_average(int height, int width, RGBTRIPLE image[height][width], POINT points[])
{
    int red_sum = 0;
    int blue_sum = 0;
    int green_sum = 0;

    for (int i = 0; i < MAX_BOX_COMPONENTS; i++)
    {
        POINT p = points[i];
        red_sum += ((p.x == -1) ? 0 : image[p.x][p.y].rgbtRed);
        green_sum += ((p.x == -1) ? 0 : image[p.x][p.y].rgbtGreen);
        blue_sum += ((p.x == -1) ? 0 : image[p.x][p.y].rgbtBlue);
    }

    int red_avg = (int)(roundf(red_sum / 9));
    int green_avg = (int)(roundf(green_sum / 9));
    int blue_avg = (int)(roundf(blue_sum / 9));

    return (RGBTRIPLE) {.rgbtBlue = blue_avg, .rgbtGreen = green_avg, .rgbtRed = red_avg};
}

void add_point(int height, int width, RGBTRIPLE image[height][width], POINT point, POINT points[], int current_index)
{
    if (point.x >= 0 && point.y >= 0 && point.x < width && point.y < height)
    {
        points[current_index] = point;
    }
}