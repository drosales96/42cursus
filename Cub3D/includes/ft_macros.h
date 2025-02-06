/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/02/06 11:11:08 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

/**
 * Standard image sizes in pixels
 * 	1920 * 1080 HDTV, 16:9, presentations, RRSS images
 *  1280 * 720 HD, 16:9, photography and cinema
 *  1080 * 1080 RRSS publications and profile images, 1:1
 * 
 * FOV => Filed of Vision
 * 
 */

# define WIDTH					1920
# define HEIGHT					1280
# define WALL_SIZE				640
# define FOV					60 
# define M_PI					3.14159265358979323846
# define SIDES_CUBE				6
# define RGB_VALID_MIN			1
# define RGB_VALID_MAX			255

# define INIT_ERR				"42Cub3d say: "
# define ARROW					"==> "
# define NUM_ARGV_ERR			"❗1️⃣ Incorrect number of arguments, expected \
one."
# define SHORT_NAME_ERR			"🗺️ Map name is very short!!!"
# define EXT_ERR				"❌ⓔⓧⓣ File extension error!!!"
# define INIT_MAP_ERR			"🌎 Error initializing map!!!"
# define FLOOR_OR_SKY_ERR		"❗Error rendering the ground or the \
sky."
# define IMG_TO_WINDOW_ERR		"❗Error in function while rendering \
process."
# define INV_CHAR_ERR			"❗Invalid character in first line."
# define INV_CHAR2_ERR			"❗Invalid character in last line."
# define CHAR1_ERR				"❌ⓒⓗⓐⓡ Wrong character "
# define CHAR2_ERR				"... at map line "
# define CHAR3_ERR				" in the position "
# define SIDE_LEFT_ERR			"❗Map left side isn't closed properly."
# define SIDE_RIGHT_ERR			"❗Map right side isn't closed properly."
# define LINE_ERR				"Error at line: "
# define FORB_SPC_ERR			"❗Forbidden space "
# define FORB_SPC2_ERR			"on the line "
# define PLAYERS_0_ERR			"❗No player on the map. There must be one."
# define PLAYERS_NO1_ERR		"❗Too many players on the map. There must be \
one."
# define MLX_INIT_ERR			"❗Error, MLX isn´t working correctly!!!"
# define OPEN_TEXTURE_ERR		"📖 Error, could not open texture file!!!"
# define OPEN_ERR				"📖 Error opening source file!!!"
# define CLOSED_ERR				"📚 Error closing source file!!!"
# define OPEN_MAP_ERR			"🗺️ Error opening map."
# define READ_ERR				"❗Error reading line with GNL."
# define SPLIT_ERR				"❗Error in function ft_split."
# define MATRIX_TO_STR_ERR		"❗Error in function ft_matrix_to_str"
# define FT_STRTRIM_ERR			"❗Error in function ft_strtrim"
# define FT_SPLIT_ERR			"❗Error in ft_map_spliting with ft_split!"
# define MAP_ERR				"❗Error, map is missing!"
# define EXTRA_LINE_ERR			"❗Error, extra line in the map!"
# define IDENT_ERR				"❗Identifier "
# define IDENT2_ERR				" is not present."
# define IDENT3_ERR				"❗Invalid identifier."
# define RGB_ERR				"❗Wrong rgb value."
# define FORMAT_RGB_ERR			"❗Invalid RGB format."
# define ARG_RGB_ERR			"❗Wrong value rgb in argument."
# define LINE2_ERR				" in the line "
# define ARG_FILE_ERR			"❗Extra argument in file."
# define TEXTURE_ERR			"❗Wrong texture format."
# define TEXTURE_2_ERR			"Error in row: "
# define NORTH_ERR				"🌎 Error loading image of North Wall..."
# define SOUTH_ERR				"🌎 Error loading image of South Wall..."
# define EAST_ERR				"🌎 Error loading image of East Wall..."
# define WEST_ERR				"🌎 Error loading image of West Wall..."
# define DUP_NO_ERR				"❗Duplicate NORTH texture identifier."
# define DUP_SO_ERR				"❗Duplicate SOUTH texture identifier."
# define DUP_EA_ERR				"❗Duplicate EAST texture identifier."
# define DUP_WE_ERR				"❗Duplicate WEST texture identifier."
# define RR_INDICATOR			"red = "
# define GR_INDICATOR			"green = "
# define BR_INDICATOR			"blue = "
# define CEIL					"CEILING"
# define FLOOR					"FLOOR"
# define NORTH					"NORTH"
# define SOUTH					"SOUTH"
# define EAST					"EAST"
# define WEST					"WEST"
# define NORTH_MIN				"N"
# define SOUTH_MIN				"S"
# define EAST_MIN				"E"
# define WEST_MIN				"W"
# define FLOOR_MIN				"F"
# define CEIL_MIN				"C"
# define NORTH_ABBREV			"NO"
# define SOUTH_ABBREV			"SO"
# define EAST_ABBREV			"EA"
# define WEST_ABBREV			"WE"
# define NORTH_LETTER			'N'
# define SOUTH_LETTER			'S'
# define EAST_LETTER			'E'
# define WEST_LETTER			'W'

#endif