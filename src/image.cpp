#include "game-lib.h"

Image::Image(const u8 * image){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
    rec.set_w(texture->w);
    rec.set_h(texture->h);
}

Image::Image(const u8 * image, float px, float py){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
    position.x = px;
    position.y = py;
    rec.set_w(texture->w);
    rec.set_h(texture->h);
}

Image::Image(const u8 * image, float px, float py, float sx, float sy, float _rotation, u32 _color){
    GRRLIB_texImg *a = GRRLIB_LoadTexture(image);
    texture = a;
    rotation = _rotation;
    position.x = px;
    position.y = py;
    scale.x = sx;
    scale.y = sy;
    color = _color;
    rec.set_h(texture->h*sx);
    rec.set_w(texture->w*sy);
}

void Image::set_pos(float px, float py){
    position.x = px;
    position.y = py;
    rec.set_pos(px, py);
}
void Image::set_scale(float sx, float sy){
    scale.x = sx;
    scale.y = sy;
    rec.set_h(texture->h*sy);
    rec.set_w(texture->w*sx);

}
void Image::set_rotation(float rot){
    rotation = rot;
}
void Image::set_color(u32 col){
    color = col;
}

void Image::move(float x, float y){
    position.x += x;
    position.y -= y;
    rec.set_pos(position.x, position.y);
}

pos Image::get_pos(){ 
    return position;
    }
pos Image::get_scale(){ 
    return scale;
    }
float Image::get_rotation(){ 
    return rotation;
    }

const GRRLIB_texImg * Image::get_img(){
    return texture;
}

void Image::draw(){
    GRRLIB_DrawImg(position.x, position.y, texture, rotation, scale.x, scale.y, color);
}
void Image::draw(float px, float py){
    GRRLIB_DrawImg(px, py, texture, rotation, scale.x, scale.y, color);
}