void move_player(Sprite* player, float *angulo)
{
    if(IsKeyDown(KEY_D))
    {
        player->dest_rect.x = player->dest_rect.x + VEL * GetFrameTime();

        *angulo = *angulo + ROT;
    }
    if(IsKeyDown(KEY_A))
    {
        player->dest_rect.x = player->dest_rect.x - VEL * GetFrameTime();
        *angulo = *angulo - ROT;

    }
    if(IsKeyDown(KEY_S))
    {
        player->dest_rect.y = player->dest_rect.y + VEL * GetFrameTime();
        

    }
    if(IsKeyDown(KEY_W))
    {
        player->dest_rect.y = player->dest_rect.y - VEL * GetFrameTime();

        

    }
}
