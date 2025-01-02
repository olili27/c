#include <math.h>
#include <string.h>

#include "helpers.h"

#define CAP 255
#define MAX_BOX_COMPONENTS 9
#define ROW_COL_LENGTH 3

typedef struct
{
    int x;
    int y;
} POINT;

void add_pixel_value_indices(int height, int width, RGBTRIPLE image[height][width], int x, int y, POINT points[]);

RGBTRIPLE get_average(int height, int width, RGBTRIPLE image[height][width], POINT points[]);

void add_point(int height, int width, RGBTRIPLE image[height][width], POINT point, POINT points[], int current_index);

RGBTRIPLE get_pixel_value(int height, int width, RGBTRIPLE image[height][width], POINT points[]);

uint8_t get_rgb_value_component(RGBTRIPLE rgb_struct, char *rgb_component);

uint8_t calculate_color_component(RGBTRIPLE box_matrix[ROW_COL_LENGTH][ROW_COL_LENGTH], char *color);

    // Convert image to grayscale
    void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (int)roundf((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            POINT points[MAX_BOX_COMPONENTS];

            for (int k = 0; k < MAX_BOX_COMPONENTS; k++)
            {
                points[k].x = -1;
                points[k].y = -1;
            }

            add_pixel_value_indices(height, width, copy, i, j, points);
            image[i][j] = get_average(height, width, copy, points);
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            POINT points[MAX_BOX_COMPONENTS];

            for (int k = 0; k < MAX_BOX_COMPONENTS; k++)
            {
                points[k].x = -1;
                points[k].y = -1;
            }

            add_pixel_value_indices(height, width, copy, i, j, points);
            image[i][j] = get_pixel_value(height, width, copy, points);
        }
    }
}

void add_pixel_value_indices(int height, int width, RGBTRIPLE image[height][width], int x, int y, POINT points[])
{
    POINT top_left_point = {.x = x - 1, .y = y - 1};
    add_point(height, width, image, top_left_point, points, 0);

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
    int count = 0;

    for (int i = 0; i < MAX_BOX_COMPONENTS; i++)
    {
        POINT p = points[i];
        if (p.x != -1 && p.y != -1)
        {
            red_sum += image[p.x][p.y].rgbtRed;
            green_sum += image[p.x][p.y].rgbtGreen;
            blue_sum += image[p.x][p.y].rgbtBlue;

            count++;
        }
    }

    int red_avg = (int)(roundf(red_sum / (count * 1.0)));
    int green_avg = (int)(roundf(green_sum / (count * 1.0)));
    int blue_avg = (int)(roundf(blue_sum / (count * 1.0)));

    return (RGBTRIPLE){.rgbtBlue = blue_avg, .rgbtGreen = green_avg, .rgbtRed = red_avg};
}

RGBTRIPLE get_pixel_value(int height, int width, RGBTRIPLE image[height][width], POINT points[])
{
    RGBTRIPLE box_matrix[ROW_COL_LENGTH][ROW_COL_LENGTH];
    int8_t index = 0;

    for (int i = 0; i < ROW_COL_LENGTH; i++)
    {
        for (int j = 0; j < ROW_COL_LENGTH; j++)
        {
            POINT p = points[index];
            if (p.x == -1 && p.y == -1)
            {
                box_matrix[i][j] = (RGBTRIPLE) {0, 0, 0};
            }
            else
            {
                box_matrix[i][j] = image[p.x][p.y];
            }
            index++;
        }
    }

    uint8_t red_value = calculate_color_component(box_matrix, "red");
    uint8_t green_value = calculate_color_component(box_matrix, "green");
    uint8_t blue_value = calculate_color_component(box_matrix, "blue");

    return (RGBTRIPLE){.rgbtBlue = blue_value, .rgbtGreen = green_value, .rgbtRed = red_value};
}

uint8_t get_rgb_value_component(RGBTRIPLE rgb_struct, char *rgb_component)
{
    if (strcmp(rgb_component, "blue") == 0)
    {
        return rgb_struct.rgbtBlue;
    }
    else if (strcmp(rgb_component, "red") == 0)
    {
        return rgb_struct.rgbtRed;
    }
    else
    {
        return rgb_struct.rgbtGreen;
    }
}

uint8_t calculate_color_component(RGBTRIPLE box_matrix[ROW_COL_LENGTH][ROW_COL_LENGTH], char *color)
{
    int8_t Gx[ROW_COL_LENGTH][ROW_COL_LENGTH] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int8_t Gy[ROW_COL_LENGTH][ROW_COL_LENGTH] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    int32_t gx_sum = 0;
    int32_t gy_sum = 0;

    for (int i = 0; i < ROW_COL_LENGTH; i++)
    {
        for (int j = 0; j < ROW_COL_LENGTH; j++)
        {
            uint8_t color_value = get_rgb_value_component(box_matrix[i][j], color);
            gx_sum += Gx[i][j] * color_value;
            gy_sum += Gy[i][j] * color_value;
        }
    }

    gx_sum *= gx_sum;
    gy_sum *= gy_sum;
    
    return (uint8_t) fmin(roundf(sqrtf(gx_sum + gy_sum)), CAP);
}

void add_point(int height, int width, RGBTRIPLE image[height][width], POINT point, POINT points[], int current_index)
{
    if (point.x >= 0 && point.y >= 0 && point.x < height && point.y < width)
    {
        points[current_index] = point;
    }
}


