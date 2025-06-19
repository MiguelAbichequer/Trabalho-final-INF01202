void move_player(Sprite* player)
{
    if(IsKeyDown(KEY_D))
    {
        player->dest_rect.x = player->dest_rect.x + 100.0 * GetFrameTime();
    }
    if(IsKeyDown(KEY_A))
    {
        player->dest_rect.x = player->dest_rect.x - 100.0 * GetFrameTime();
    }
    if(IsKeyDown(KEY_S))
    {
        player->dest_rect.y = player->dest_rect.y - 100.0 * GetFrameTime();
    }
    if(IsKeyDown(KEY_W))
    {
        player->dest_rect.y = player->dest_rect.y + 100.0 * GetFrameTime();
    }
}
