| **Estructura Original**    | **Campo Original**         | **Estructura Nueva**    | **Campo Nuevo**               |
|----------------------------|----------------------------|--------------------------|-------------------------------|
| **`t_data`**               | `ray_number`              | **`t_cub3d`**           | `ray_number`                 |
|                            | `move`                    |                          | `move`                       |
|                            | `file`                    |                          | `file`                       |
|                            | `map`                     |                          | `map`                        |
|                            | `player`                  |                          | `player`                     |
|                            | `textures`                |                          | `textures`                   |
|                            | `mlx`                     |                          | `mlx`                        |
|                            | `background`              |                          | `background`                 |
|                            | `walls`                   |                          | `walls`                      |
| **`t_map`**                | `map`                     | **`t_map`**             | `map`                        |
|                            | `map_size_x`              |                          | `x_map`                      |
|                            | `map_size_y`              |                          | `y_map`                      |
|                            | `map_line`                |                          | `line_map`                   |
| **`t_line`**               | `x`                       | **`t_line`**            | `x`                          |
|                            | `y`                       |                          | `y`                          |
|                            | `y0`                      |                          | `y0`                         |
|                            | `y1`                      |                          | `y1`                         |
|                            | `tex_x`                   |                          | `x_text`                     |
|                            | `tex_y`                   |                          | `y_text`                     |
| **`t_point`**              | `x`                       | **`t_paint_coord`**     | `x`                          |
|                            | `y`                       |                          | `y`                          |
| **`t_player`**             | `angle`                   | **`t_player`**          | `angle`                      |
|                            | `pos_x`                   |                          | `x_player_pos`               |
|                            | `pos_y`                   |                          | `y_player_pos`               |
|                            | `map_x`                   |                          | `x_map`                      |
|                            | `map_y`                   |                          | `y_map`                      |
|                            | `ray`                     |                          | `ray`                        |
| **`t_ray`**                | `flag`                    | **`t_ray`**             | `flag`                       |
|                            | `map_x`                   |                          | `x_map`                      |
|                            | `map_y`                   |                          | `y_map`                      |
|                            | `angle`                   |                          | `angle`                      |
|                            | `angle_ret`               |                          | `angle_ret`                  |
|                            | `pos_x`                   |                          | `x_player_pos`               |
|                            | `pos_y`                   |                          | `y_player_pos`               |
|                            | `ray_dir_x`               |                          | `ray_x`                      |
|                            | `ray_dir_y`               |                          | `ray_y`                      |
|                            | `delta_dist_x`            |                          | `ray_dist_to_x`              |
|                            | `delta_dist_y`            |                          | `ray_dist_to_y`              |
|                            | `side_dist_x`             |                          | `cell_crossing_dist_x`       |
|                            | `side_dist_y`             |                          | `cell_crossing_dist_y`       |
|                            | `perp_wall_dist`          |                          | `wall_ray_hit_dist`          |
|                            | `pixel_width_impact`      |                          | `wall_visible_height`        |
|                            | `hit`                     |                          | `ray_hit_in_map_dist`        |
|                            | `hyp_distance`            |                          | `ray_hypoteneuse_dist`       |
|                            | `ver_distance`            |                          | `vertical_ray_travel`        |
|                            | `step_x`                  |                          | `ray_move_x`                 |
|                            | `step_y`                  |                          | `ray_move_y`                 |
| **`t_texture`**            | `no_path`                 | **`t_textures`**        | `north_path`                 |
|                            | `so_path`                 |                          | `south_path`                 |
|                            | `we_path`                 |                          | `west_path`                  |
|                            | `ea_path`                 |                          | `east_path`                  |
|                            | `no_flag`                 |                          | `north_flag`                 |
|                            | `so_flag`                 |                          | `south_flag`                 |
|                            | `we_flag`                 |                          | `west_flag`                  |
|                            | `ea_flag`                 |                          | `east_flag`                  |
|                            | `c_flag`                  |                          | `sky_flag`                   |
|                            | `f_flag`                  |                          | `floor_flag`                 |
|                            | `c_color`                 |                          | `sky_color`                  |
|                            | `f_color`                 |                          | `floor_color`                |
|                            | `no_texture`              |                          | `north_text`                 |
|                            | `so_texture`              |                          | `south_text`                 |
|                            | `we_texture`              |                          | `west_text`                  |
|                            | `ea_texture`              |                          | `east_text`                  |
