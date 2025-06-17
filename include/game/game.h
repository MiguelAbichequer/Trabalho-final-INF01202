typedef struct{
    Texture2D texture; // textura do sprite.
    Rectangle dest_rect; // hitbox do sprite.
}Sprite;

void move_player(Sprite* player);
