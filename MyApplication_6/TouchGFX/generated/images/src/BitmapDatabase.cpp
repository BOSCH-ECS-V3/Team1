// 4.23.2 0xde20beba
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_widgets_button_icon_round_micro_outline_normal[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_NORMAL_ID = 0, Size: 36x36 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_icon_round_micro_outline_pressed[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_OUTLINE_PRESSED_ID = 1, Size: 36x36 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_60_tiny_rounded_disabled[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_60_TINY_ROUNDED_DISABLED_ID = 2, Size: 144x60 pixels
extern const unsigned char image_alternate_theme_images_widgets_circleprogress_backgrounds_small[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_CIRCLEPROGRESS_BACKGROUNDS_SMALL_ID = 3, Size: 110x110 pixels
extern const unsigned char image_alternate_theme_images_widgets_swipecontainer_small_off_normal[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SWIPECONTAINER_SMALL_OFF_NORMAL_ID = 4, Size: 12x12 pixels
extern const unsigned char image_alternate_theme_images_widgets_swipecontainer_small_on_normal[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SWIPECONTAINER_SMALL_ON_NORMAL_ID = 5, Size: 12x12 pixels
extern const unsigned char image_temperature_and_humidity[]; // BITMAP_TEMPERATURE_AND_HUMIDITY_ID = 6, Size: 512x512 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_widgets_button_icon_round_micro_outline_normal, 0, 36, 36, 31, 12, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_icon_round_micro_outline_pressed, 0, 36, 36, 31, 12, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 12, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_regular_height_60_tiny_rounded_disabled, 0, 144, 60, 7, 1, 130, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 58, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_circleprogress_backgrounds_small, 0, 110, 110, 100, 37, 7, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 36, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_swipecontainer_small_off_normal, 0, 12, 12, 10, 3, 1, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 6, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_swipecontainer_small_on_normal, 0, 12, 12, 10, 3, 1, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 6, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_temperature_and_humidity, 0, 512, 512, 193, 98, 51, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 328, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
