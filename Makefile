# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 10:43:55 by hpatsi            #+#    #+#              #
#    Updated: 2023/11/29 16:03:49 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFT = ./libft/libft.a

SOURCES = push_swap.c handle_input.c \
		  stack_utils.c check_state.c \
		  exec_command.c p_s_commands.c r_commands.c \
		  tiny_sort.c push_smallest_sort.c radix_sort.c \

BONUS_SOURCES = checker_bonus.c handle_input_bonus.c \
				exec_command_bonus.c p_s_commands_bonus.c r_commands_bonus.c \
				stack_utils_bonus.c check_state_bonus.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(OBJECTS): $(SOURCES)

$(LIBFT):
	make -C ./libft

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(BONUS)
	
$(BONUS_OBJECTS): $(BONUS_SOURCES)

clean:
	make clean -C ./libft
	rm -f $(OBJECTS) 
	rm -f $(BONUS_OBJECTS)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

test_inputs: $(NAME)
	@echo "\n---TESTING INPUTS---"
	@echo "\nValid inputs:"
	./$(NAME) 1 2 3
	./$(NAME) 0 1 2
	./$(NAME) 1 2 2147483647
	./$(NAME) -2147483648 1 2
	@echo "\nInvalid inputs:"
	./$(NAME) 1 2 1
	./$(NAME) 1 2 2147483648
	./$(NAME) -2147483649 1 2
	./$(NAME) 1 2 a
	./$(NAME) 1 2 +3
	./$(NAME) 1 2 3a

test: test_inputs $(NAME)
	@echo "\n---TESTING SORT---"
	@echo "\n1 ints:"
	@./$(NAME) "1" | ./checker_Mac "1"
	@echo "\n2 ints:"
	@./$(NAME) "2 1" | ./checker_Mac "2 1"
	@./$(NAME) "1 2" | ./checker_Mac "1 2"
	@echo "\n3 ints:"
	@./$(NAME) "2 1 3" | ./checker_Mac "2 1 3"
	@./$(NAME) "2 3 1" | ./checker_Mac "2 3 1"
	@./$(NAME) "3 2 1" | ./checker_Mac "3 2 1"
	@echo "\n5 ints:"
	@./$(NAME) "5 4 2 1 3" | ./checker_Mac "5 4 2 1 3"
	@./$(NAME) "2 1 3 5 4" | ./checker_Mac "2 1 3 5 4"
	@./$(NAME) "3 2 5 4 1" | ./checker_Mac "3 2 5 4 1"
	@./$(NAME) "3 5 1 4 2" | ./checker_Mac "3 5 1 4 2"
	@./$(NAME) "1006904419 -1180256924 -1509642107 -969477600 -1102846459" | ./checker_Mac "1006904419 -1180256924 -1509642107 -969477600 -1102846459"
	@echo "\n10 ints:"
	@./$(NAME) "5 9 6 3 2 1 7 10 4 8" | ./checker_Mac "5 9 6 3 2 1 7 10 4 8"
	@./$(NAME) "5 9 2 4 1 10 7 3 6 8" | ./checker_Mac "5 9 2 4 1 10 7 3 6 8"
	@./$(NAME) "8 6 10 4 7 2 5 3 9 1" | ./checker_Mac "8 6 10 4 7 2 5 3 9 1"
	@./$(NAME) "9 1 2 8 6 3 4 5 10 7" | ./checker_Mac "9 1 2 8 6 3 4 5 10 7"
	@./$(NAME) "-1635033433 717357484 -1593749994 486531990 2135149960 1943454142 -1149511891 1298285369 -337719654 1676331747" | ./checker_Mac "-1635033433 717357484 -1593749994 486531990 2135149960 1943454142 -1149511891 1298285369 -337719654 1676331747"
	@echo "\n20 ints:"
	@./$(NAME) "9 18 16 5 10 11 17 1 14 20 4 3 2 8 12 13 15 19 7 6" | ./checker_Mac "9 18 16 5 10 11 17 1 14 20 4 3 2 8 12 13 15 19 7 6"
	@./$(NAME) "6 4 7 5 19 10 3 16 18 14 8 20 2 11 12 9 15 17 13 1" | ./checker_Mac "6 4 7 5 19 10 3 16 18 14 8 20 2 11 12 9 15 17 13 1"
	@./$(NAME) "10 1 11 12 15 19 5 4 18 7 2 9 6 17 8 16 20 14 13 3" | ./checker_Mac "10 1 11 12 15 19 5 4 18 7 2 9 6 17 8 16 20 14 13 3"
	@./$(NAME) "13 20 6 5 19 2 17 4 14 15 7 1 16 3 9 12 10 11 8 18" | ./checker_Mac "13 20 6 5 19 2 17 4 14 15 7 1 16 3 9 12 10 11 8 18"
	@./$(NAME) "854864216 -1252295129 962585084 -2048916796 -1840946501 1303321463 -324846771 1314034301 1109095800 -796998342 -123240211 -1484118559 1923015127 -1800742947 2076111100 -349526606 30119343 -1310526683 -895019249 1854126999" | ./checker_Mac "854864216 -1252295129 962585084 -2048916796 -1840946501 1303321463 -324846771 1314034301 1109095800 -796998342 -123240211 -1484118559 1923015127 -1800742947 2076111100 -349526606 30119343 -1310526683 -895019249 1854126999"
	@echo "\n50 ints:"
	@./$(NAME) "36 23 8 31 38 13 32 41 27 11 30 25 19 33 10 7 18 48 45 35 44 24 20 21 3 34 47 15 40 26 50 39 17 28 1 6 2 22 49 46 37 5 43 14 29 16 12 4 42 9" | ./checker_Mac "36 23 8 31 38 13 32 41 27 11 30 25 19 33 10 7 18 48 45 35 44 24 20 21 3 34 47 15 40 26 50 39 17 28 1 6 2 22 49 46 37 5 43 14 29 16 12 4 42 9"
	@./$(NAME) "45 22 44 31 38 14 26 50 12 18 34 9 43 19 21 6 23 20 29 11 4 3 5 1 17 27 46 49 10 39 13 2 15 47 33 30 7 16 41 35 48 40 36 25 42 24 37 28 32 8" | ./checker_Mac "45 22 44 31 38 14 26 50 12 18 34 9 43 19 21 6 23 20 29 11 4 3 5 1 17 27 46 49 10 39 13 2 15 47 33 30 7 16 41 35 48 40 36 25 42 24 37 28 32 8"
	@./$(NAME) "13 1 47 37 20 25 5 27 8 36 46 34 41 40 17 19 22 45 48 24 3 6 38 28 18 21 4 44 26 9 2 29 7 31 23 14 10 39 32 50 49 12 42 43 35 16 11 15 33 30" | ./checker_Mac "13 1 47 37 20 25 5 27 8 36 46 34 41 40 17 19 22 45 48 24 3 6 38 28 18 21 4 44 26 9 2 29 7 31 23 14 10 39 32 50 49 12 42 43 35 16 11 15 33 30"
	@./$(NAME) "39 32 7 16 25 31 4 29 41 6 50 43 21 34 22 48 15 44 20 24 33 10 14 47 26 28 38 18 12 40 30 35 45 9 1 13 27 49 36 42 19 5 11 37 17 8 46 2 23 3" | ./checker_Mac "39 32 7 16 25 31 4 29 41 6 50 43 21 34 22 48 15 44 20 24 33 10 14 47 26 28 38 18 12 40 30 35 45 9 1 13 27 49 36 42 19 5 11 37 17 8 46 2 23 3"
	@./$(NAME) "2111557516 99482693 -1072509746 611425983 310728508 -1217314621 -1468072224 838323800 941159815 221490812 -992140576 -1483019848 -1452428613 -1101522176 725055990 -1959969523 -1454355593 1505314749 1960287514 977154727 814535631 782218152 -1127769727 780700808 128329449 -1950873333 604838020 887892543 747252472 -237577899 -851711941 -257913910 1503116542 -1287920633 146094470 -636634579 -2100483839 -1562893450 -163060246 -1315924909 -683970012 1441693114 1378953641 228137024 366491626 1302352564 -1730589423 -2038975695 -1536231256 354807350" | ./checker_Mac "2111557516 99482693 -1072509746 611425983 310728508 -1217314621 -1468072224 838323800 941159815 221490812 -992140576 -1483019848 -1452428613 -1101522176 725055990 -1959969523 -1454355593 1505314749 1960287514 977154727 814535631 782218152 -1127769727 780700808 128329449 -1950873333 604838020 887892543 747252472 -237577899 -851711941 -257913910 1503116542 -1287920633 146094470 -636634579 -2100483839 -1562893450 -163060246 -1315924909 -683970012 1441693114 1378953641 228137024 366491626 1302352564 -1730589423 -2038975695 -1536231256 354807350"
	@echo "\n100 ints:"
	@./$(NAME) "33 73 89 43 19 50 92 54 37 61 45 3 72 7 8 82 65 59 23 1 17 86 15 76 34 5 84 74 71 41 64 80 93 60 29 75 30 62 95 18 63 70 16 83 24 38 49 11 66 99 81 32 25 36 53 55 31 96 78 39 47 87 77 42 88 9 79 28 2 69 56 98 6 94 22 85 91 58 40 44 14 12 97 21 90 35 46 26 52 4 20 10 48 100 13 67 57 51 27 68" | ./checker_Mac "33 73 89 43 19 50 92 54 37 61 45 3 72 7 8 82 65 59 23 1 17 86 15 76 34 5 84 74 71 41 64 80 93 60 29 75 30 62 95 18 63 70 16 83 24 38 49 11 66 99 81 32 25 36 53 55 31 96 78 39 47 87 77 42 88 9 79 28 2 69 56 98 6 94 22 85 91 58 40 44 14 12 97 21 90 35 46 26 52 4 20 10 48 100 13 67 57 51 27 68"
	@./$(NAME) "90 42 86 63 73 83 9 13 96 56 57 69 79 20 75 87 6 4 48 55 32 22 54 77 40 38 88 89 52 95 17 33 51 46 14 39 92 85 26 30 80 47 60 16 5 76 24 78 21 58 23 37 34 71 91 82 81 59 1 45 49 19 67 29 66 10 53 70 8 11 36 2 72 50 74 3 84 15 99 28 41 27 97 43 7 62 35 25 68 61 31 100 18 64 94 12 98 44 65 93" | ./checker_Mac "90 42 86 63 73 83 9 13 96 56 57 69 79 20 75 87 6 4 48 55 32 22 54 77 40 38 88 89 52 95 17 33 51 46 14 39 92 85 26 30 80 47 60 16 5 76 24 78 21 58 23 37 34 71 91 82 81 59 1 45 49 19 67 29 66 10 53 70 8 11 36 2 72 50 74 3 84 15 99 28 41 27 97 43 7 62 35 25 68 61 31 100 18 64 94 12 98 44 65 93"
	@./$(NAME) "91 86 81 53 51 70 60 12 96 23 49 28 93 82 100 39 18 63 35 58 62 85 95 57 74 2 15 47 16 30 50 27 87 77 22 5 75 76 32 11 90 26 46 34 73 20 41 89 78 65 7 17 94 66 67 79 24 38 83 72 10 52 54 59 56 98 19 42 8 43 13 4 9 21 61 92 25 64 40 3 68 6 99 88 44 14 36 29 33 48 69 80 37 31 97 1 55 45 84 71" | ./checker_Mac "91 86 81 53 51 70 60 12 96 23 49 28 93 82 100 39 18 63 35 58 62 85 95 57 74 2 15 47 16 30 50 27 87 77 22 5 75 76 32 11 90 26 46 34 73 20 41 89 78 65 7 17 94 66 67 79 24 38 83 72 10 52 54 59 56 98 19 42 8 43 13 4 9 21 61 92 25 64 40 3 68 6 99 88 44 14 36 29 33 48 69 80 37 31 97 1 55 45 84 71"
	@./$(NAME) "1 25 8 95 51 77 9 83 7 23 12 32 97 100 39 29 70 91 55 96 61 45 53 86 41 78 63 52 57 42 82 72 34 58 90 20 59 49 36 4 11 3 73 76 38 16 37 98 48 30 35 44 85 54 24 94 81 67 88 18 56 10 13 33 74 26 14 46 66 17 21 87 6 43 80 40 75 84 15 19 5 47 28 2 68 62 89 92 27 93 65 71 64 99 31 60 50 22 69 79" | ./checker_Mac "1 25 8 95 51 77 9 83 7 23 12 32 97 100 39 29 70 91 55 96 61 45 53 86 41 78 63 52 57 42 82 72 34 58 90 20 59 49 36 4 11 3 73 76 38 16 37 98 48 30 35 44 85 54 24 94 81 67 88 18 56 10 13 33 74 26 14 46 66 17 21 87 6 43 80 40 75 84 15 19 5 47 28 2 68 62 89 92 27 93 65 71 64 99 31 60 50 22 69 79"
	@./$(NAME) "912185655 -332636523 916033637 -2132842018 -886455654 1984469062 -665988056 -2128528272 -652366396 1890712146 -1111192772 1860313660 1954252965 -1882867204 647012169 -867480348 1244349827 1768936022 1173843795 1677654078 1563878000 -973009403 -1998021895 956958643 -527772508 2111550089 -783454104 -1644670367 2086750144 -1567157405 -1619179747 -841069667 1737261635 36205642 -1495673143 -1181585599 1273988833 1024827627 1505425466 -2063568364 -807806201 1249650424 2032459035 1097054954 2125638908 611568850 137849599 -577211959 58661855 561241433 1725483225 -1180246697 -962021497 600150748 -774844472 -41814428 -660592200 -1598167231 317778027 -1622110378 -531508205 1630115720 150534045 -1124481378 715142731 926894485 -214692371 -1716455227 453114352 -565001830 1019068356 -2079254966 616937736 204970923 1275399208 -1970207774 -1356582430 1388597860 283927963 -1310751849 623935123 -1997368215 -1449776 903195190 -35352028 -1928136494 -1254734084 -1791376044 1600170378 528842705 163344650 -1565442194 -1776297561 -237818791 -389398834 349465266 560499303 325363274 -374858785 1053038135" | ./checker_Mac "912185655 -332636523 916033637 -2132842018 -886455654 1984469062 -665988056 -2128528272 -652366396 1890712146 -1111192772 1860313660 1954252965 -1882867204 647012169 -867480348 1244349827 1768936022 1173843795 1677654078 1563878000 -973009403 -1998021895 956958643 -527772508 2111550089 -783454104 -1644670367 2086750144 -1567157405 -1619179747 -841069667 1737261635 36205642 -1495673143 -1181585599 1273988833 1024827627 1505425466 -2063568364 -807806201 1249650424 2032459035 1097054954 2125638908 611568850 137849599 -577211959 58661855 561241433 1725483225 -1180246697 -962021497 600150748 -774844472 -41814428 -660592200 -1598167231 317778027 -1622110378 -531508205 1630115720 150534045 -1124481378 715142731 926894485 -214692371 -1716455227 453114352 -565001830 1019068356 -2079254966 616937736 204970923 1275399208 -1970207774 -1356582430 1388597860 283927963 -1310751849 623935123 -1997368215 -1449776 903195190 -35352028 -1928136494 -1254734084 -1791376044 1600170378 528842705 163344650 -1565442194 -1776297561 -237818791 -389398834 349465266 560499303 325363274 -374858785 1053038135"
	@echo "\n500 ints:"
	@./$(NAME) "386 267 390 328 457 281 136 91 324 72 411 59 12 325 39 276 440 134 237 433 200 302 50 490 376 19 370 38 418 67 79 92 199 406 417 485 392 172 60 215 89 379 410 323 400 407 365 381 268 284 182 202 96 194 351 17 254 46 493 234 138 422 255 247 5 114 415 481 338 7 339 478 6 333 497 214 308 341 157 416 368 428 52 419 402 152 217 475 489 283 465 192 121 25 109 442 160 297 116 431 87 173 13 185 65 34 467 389 335 494 61 495 54 156 80 306 142 103 491 63 179 238 326 359 401 122 140 204 403 289 62 24 42 298 41 209 170 193 319 229 273 378 235 119 180 9 161 184 452 429 94 27 399 213 474 346 118 480 64 15 318 239 278 449 468 32 174 314 101 472 299 385 282 56 206 2 251 384 248 437 307 154 8 355 57 380 107 327 240 55 438 374 30 10 473 304 195 344 360 158 189 310 144 259 249 155 498 439 139 459 111 228 208 427 81 369 4 477 436 321 317 74 44 280 127 232 421 366 357 246 353 131 409 277 441 236 499 71 293 394 352 18 146 130 414 22 262 412 224 151 356 471 40 329 244 387 295 75 486 488 320 476 448 496 73 163 115 345 141 104 252 362 108 334 133 261 482 290 126 112 167 83 11 434 230 287 203 43 150 165 258 432 191 260 311 58 253 242 125 29 105 483 462 226 358 82 331 85 187 425 36 197 188 313 303 93 292 430 372 342 332 397 456 220 86 469 186 413 207 68 382 391 395 250 470 183 70 145 181 132 361 153 110 16 148 393 375 479 23 294 227 28 288 198 364 461 78 90 272 354 443 241 143 159 464 275 301 270 291 458 45 77 223 446 383 405 88 426 222 51 129 164 99 14 265 26 398 97 137 484 113 225 205 66 263 106 340 53 377 348 373 367 162 305 285 424 315 120 147 451 274 500 210 169 455 20 211 190 21 492 423 466 447 168 460 37 286 1 48 98 124 388 128 47 196 231 31 3 463 49 35 337 69 177 102 435 396 33 445 420 264 444 487 149 256 221 322 84 245 201 243 257 216 176 336 347 219 279 454 316 123 135 453 212 343 404 117 218 171 178 371 363 309 330 408 233 296 100 166 76 175 349 266 450 350 95 300 312 269 271" | ./checker_Mac "386 267 390 328 457 281 136 91 324 72 411 59 12 325 39 276 440 134 237 433 200 302 50 490 376 19 370 38 418 67 79 92 199 406 417 485 392 172 60 215 89 379 410 323 400 407 365 381 268 284 182 202 96 194 351 17 254 46 493 234 138 422 255 247 5 114 415 481 338 7 339 478 6 333 497 214 308 341 157 416 368 428 52 419 402 152 217 475 489 283 465 192 121 25 109 442 160 297 116 431 87 173 13 185 65 34 467 389 335 494 61 495 54 156 80 306 142 103 491 63 179 238 326 359 401 122 140 204 403 289 62 24 42 298 41 209 170 193 319 229 273 378 235 119 180 9 161 184 452 429 94 27 399 213 474 346 118 480 64 15 318 239 278 449 468 32 174 314 101 472 299 385 282 56 206 2 251 384 248 437 307 154 8 355 57 380 107 327 240 55 438 374 30 10 473 304 195 344 360 158 189 310 144 259 249 155 498 439 139 459 111 228 208 427 81 369 4 477 436 321 317 74 44 280 127 232 421 366 357 246 353 131 409 277 441 236 499 71 293 394 352 18 146 130 414 22 262 412 224 151 356 471 40 329 244 387 295 75 486 488 320 476 448 496 73 163 115 345 141 104 252 362 108 334 133 261 482 290 126 112 167 83 11 434 230 287 203 43 150 165 258 432 191 260 311 58 253 242 125 29 105 483 462 226 358 82 331 85 187 425 36 197 188 313 303 93 292 430 372 342 332 397 456 220 86 469 186 413 207 68 382 391 395 250 470 183 70 145 181 132 361 153 110 16 148 393 375 479 23 294 227 28 288 198 364 461 78 90 272 354 443 241 143 159 464 275 301 270 291 458 45 77 223 446 383 405 88 426 222 51 129 164 99 14 265 26 398 97 137 484 113 225 205 66 263 106 340 53 377 348 373 367 162 305 285 424 315 120 147 451 274 500 210 169 455 20 211 190 21 492 423 466 447 168 460 37 286 1 48 98 124 388 128 47 196 231 31 3 463 49 35 337 69 177 102 435 396 33 445 420 264 444 487 149 256 221 322 84 245 201 243 257 216 176 336 347 219 279 454 316 123 135 453 212 343 404 117 218 171 178 371 363 309 330 408 233 296 100 166 76 175 349 266 450 350 95 300 312 269 271"
	@./$(NAME) "62 315 200 50 487 405 497 115 288 353 284 430 213 195 435 454 101 326 314 116 165 155 458 358 70 417 227 143 282 357 410 153 482 96 98 436 4 484 117 393 154 396 346 79 212 9 120 64 55 177 110 486 303 144 26 8 58 182 409 208 111 360 281 351 190 308 145 266 242 197 390 249 268 233 83 77 270 302 135 48 137 416 321 488 178 254 365 21 45 258 332 237 88 323 147 455 3 53 334 456 82 467 179 301 372 247 356 156 418 324 340 259 483 469 78 413 354 333 175 245 472 125 397 429 183 49 295 452 19 260 171 220 84 217 146 494 185 459 379 163 446 76 186 322 359 174 479 32 39 251 279 188 127 460 18 287 61 450 399 443 345 59 60 318 28 113 85 109 228 173 475 253 489 29 252 493 276 104 272 223 244 298 481 338 371 226 231 2 202 218 37 128 457 329 401 224 291 105 172 192 305 209 364 1 6 496 5 222 97 306 378 451 403 463 330 380 369 387 92 44 87 267 56 433 262 152 462 106 285 102 94 385 140 187 169 57 51 132 439 350 277 363 465 261 205 348 235 347 394 264 316 256 280 214 381 232 474 12 86 10 384 52 75 344 476 81 325 426 440 123 366 313 421 164 423 66 206 441 239 219 400 194 319 420 90 362 126 274 320 221 240 33 189 480 311 328 93 289 422 139 71 404 150 54 95 149 485 181 134 63 89 473 492 238 31 236 402 498 304 415 72 24 151 447 15 199 91 411 444 265 370 337 389 286 425 294 442 69 471 414 34 122 464 495 461 310 30 376 449 108 431 133 300 361 445 168 157 124 193 225 490 448 35 395 297 246 275 234 20 386 336 131 40 43 283 180 335 38 23 257 67 22 309 184 248 166 299 278 107 392 419 170 352 327 211 210 216 388 80 46 230 342 478 290 407 243 434 130 355 112 25 406 162 141 215 374 273 14 73 377 176 437 148 296 427 428 269 453 129 339 438 432 349 118 412 241 499 119 468 17 196 201 292 271 65 312 103 159 466 255 229 373 367 375 317 341 203 100 391 263 41 42 68 13 36 307 121 398 408 7 47 99 491 16 198 160 161 27 11 74 293 470 204 331 114 138 383 500 382 250 424 136 207 158 343 167 368 477 142 191" | ./checker_Mac "62 315 200 50 487 405 497 115 288 353 284 430 213 195 435 454 101 326 314 116 165 155 458 358 70 417 227 143 282 357 410 153 482 96 98 436 4 484 117 393 154 396 346 79 212 9 120 64 55 177 110 486 303 144 26 8 58 182 409 208 111 360 281 351 190 308 145 266 242 197 390 249 268 233 83 77 270 302 135 48 137 416 321 488 178 254 365 21 45 258 332 237 88 323 147 455 3 53 334 456 82 467 179 301 372 247 356 156 418 324 340 259 483 469 78 413 354 333 175 245 472 125 397 429 183 49 295 452 19 260 171 220 84 217 146 494 185 459 379 163 446 76 186 322 359 174 479 32 39 251 279 188 127 460 18 287 61 450 399 443 345 59 60 318 28 113 85 109 228 173 475 253 489 29 252 493 276 104 272 223 244 298 481 338 371 226 231 2 202 218 37 128 457 329 401 224 291 105 172 192 305 209 364 1 6 496 5 222 97 306 378 451 403 463 330 380 369 387 92 44 87 267 56 433 262 152 462 106 285 102 94 385 140 187 169 57 51 132 439 350 277 363 465 261 205 348 235 347 394 264 316 256 280 214 381 232 474 12 86 10 384 52 75 344 476 81 325 426 440 123 366 313 421 164 423 66 206 441 239 219 400 194 319 420 90 362 126 274 320 221 240 33 189 480 311 328 93 289 422 139 71 404 150 54 95 149 485 181 134 63 89 473 492 238 31 236 402 498 304 415 72 24 151 447 15 199 91 411 444 265 370 337 389 286 425 294 442 69 471 414 34 122 464 495 461 310 30 376 449 108 431 133 300 361 445 168 157 124 193 225 490 448 35 395 297 246 275 234 20 386 336 131 40 43 283 180 335 38 23 257 67 22 309 184 248 166 299 278 107 392 419 170 352 327 211 210 216 388 80 46 230 342 478 290 407 243 434 130 355 112 25 406 162 141 215 374 273 14 73 377 176 437 148 296 427 428 269 453 129 339 438 432 349 118 412 241 499 119 468 17 196 201 292 271 65 312 103 159 466 255 229 373 367 375 317 341 203 100 391 263 41 42 68 13 36 307 121 398 408 7 47 99 491 16 198 160 161 27 11 74 293 470 204 331 114 138 383 500 382 250 424 136 207 158 343 167 368 477 142 191"
	@./$(NAME) "337 187 344 169 106 211 298 61 403 382 186 405 281 423 371 3 273 409 372 134 311 479 188 158 338 221 248 21 48 57 379 444 296 31 229 287 432 251 407 243 99 455 209 358 55 83 264 459 75 109 320 224 205 156 67 307 93 189 458 396 174 69 231 256 282 346 226 206 181 481 263 401 164 380 381 484 245 429 267 173 329 108 327 316 258 348 353 356 26 417 154 306 261 12 235 122 236 274 45 49 330 500 257 345 118 246 144 313 272 150 157 450 11 215 454 2 457 460 351 376 43 334 470 414 82 103 416 182 72 357 375 363 129 190 119 24 64 400 467 291 378 63 152 32 427 253 220 240 262 194 192 441 44 295 135 480 171 241 447 120 143 13 373 398 131 461 364 397 170 185 465 96 234 212 42 255 168 323 305 419 172 493 494 177 318 390 368 68 228 328 88 54 440 18 252 406 498 62 476 336 343 10 191 37 238 415 290 112 210 260 105 60 85 20 175 266 102 202 162 289 151 420 321 146 237 421 394 309 195 361 464 218 483 333 124 244 140 40 370 4 342 350 70 14 308 95 16 387 431 17 142 254 302 478 474 136 167 113 179 482 402 365 411 52 488 312 366 412 404 153 125 410 91 297 58 196 490 271 53 249 41 466 250 428 283 303 360 176 315 89 349 276 110 347 332 155 232 117 25 201 193 425 7 116 279 304 165 408 199 331 317 286 399 76 198 278 130 292 15 33 443 496 437 445 469 159 497 138 392 471 46 280 288 355 227 473 8 34 489 433 391 123 439 374 183 28 200 354 132 485 9 79 339 36 225 35 38 451 413 310 22 50 121 74 80 104 126 456 86 100 5 388 389 293 147 453 19 78 160 269 495 178 204 426 84 341 51 446 395 285 223 242 23 133 161 284 137 219 492 90 47 340 325 369 71 299 233 66 452 448 148 268 424 383 326 127 435 475 436 203 145 217 377 477 163 393 462 322 1 107 230 491 111 438 468 214 324 29 166 222 422 115 335 6 487 259 430 65 463 277 300 207 434 184 141 87 139 92 56 275 239 486 101 301 81 59 472 27 265 208 97 149 270 114 180 367 314 362 77 384 352 39 213 98 216 197 319 73 359 247 30 449 499 128 418 94 294 385 386 442" | ./checker_Mac "337 187 344 169 106 211 298 61 403 382 186 405 281 423 371 3 273 409 372 134 311 479 188 158 338 221 248 21 48 57 379 444 296 31 229 287 432 251 407 243 99 455 209 358 55 83 264 459 75 109 320 224 205 156 67 307 93 189 458 396 174 69 231 256 282 346 226 206 181 481 263 401 164 380 381 484 245 429 267 173 329 108 327 316 258 348 353 356 26 417 154 306 261 12 235 122 236 274 45 49 330 500 257 345 118 246 144 313 272 150 157 450 11 215 454 2 457 460 351 376 43 334 470 414 82 103 416 182 72 357 375 363 129 190 119 24 64 400 467 291 378 63 152 32 427 253 220 240 262 194 192 441 44 295 135 480 171 241 447 120 143 13 373 398 131 461 364 397 170 185 465 96 234 212 42 255 168 323 305 419 172 493 494 177 318 390 368 68 228 328 88 54 440 18 252 406 498 62 476 336 343 10 191 37 238 415 290 112 210 260 105 60 85 20 175 266 102 202 162 289 151 420 321 146 237 421 394 309 195 361 464 218 483 333 124 244 140 40 370 4 342 350 70 14 308 95 16 387 431 17 142 254 302 478 474 136 167 113 179 482 402 365 411 52 488 312 366 412 404 153 125 410 91 297 58 196 490 271 53 249 41 466 250 428 283 303 360 176 315 89 349 276 110 347 332 155 232 117 25 201 193 425 7 116 279 304 165 408 199 331 317 286 399 76 198 278 130 292 15 33 443 496 437 445 469 159 497 138 392 471 46 280 288 355 227 473 8 34 489 433 391 123 439 374 183 28 200 354 132 485 9 79 339 36 225 35 38 451 413 310 22 50 121 74 80 104 126 456 86 100 5 388 389 293 147 453 19 78 160 269 495 178 204 426 84 341 51 446 395 285 223 242 23 133 161 284 137 219 492 90 47 340 325 369 71 299 233 66 452 448 148 268 424 383 326 127 435 475 436 203 145 217 377 477 163 393 462 322 1 107 230 491 111 438 468 214 324 29 166 222 422 115 335 6 487 259 430 65 463 277 300 207 434 184 141 87 139 92 56 275 239 486 101 301 81 59 472 27 265 208 97 149 270 114 180 367 314 362 77 384 352 39 213 98 216 197 319 73 359 247 30 449 499 128 418 94 294 385 386 442"
	@./$(NAME) "112 78 283 489 277 428 337 425 416 218 474 30 426 244 187 443 222 153 150 338 381 232 437 2 331 323 175 412 261 317 195 309 133 468 401 445 106 383 71 101 35 465 259 475 485 128 371 155 402 193 483 9 102 164 226 493 113 94 446 303 347 10 498 215 228 271 162 98 114 79 93 179 199 163 254 490 220 126 14 367 379 231 160 68 107 278 472 330 321 413 120 256 288 108 399 25 340 43 391 37 242 205 1 121 341 324 492 482 27 209 139 103 488 314 429 461 40 116 124 422 15 32 203 235 73 500 134 480 145 28 233 373 424 85 178 171 353 346 409 299 289 87 313 50 350 191 144 119 182 487 83 439 41 444 224 148 221 430 169 53 151 349 333 64 351 363 421 479 400 466 496 48 77 181 99 411 239 63 258 185 96 115 123 38 234 453 240 158 264 477 471 339 431 301 138 322 20 356 16 308 253 167 423 268 361 291 420 455 469 281 282 157 433 290 380 462 135 476 311 370 142 376 458 97 109 31 201 192 47 230 464 206 415 245 295 159 66 328 312 255 432 91 365 262 304 348 417 212 207 26 355 92 326 204 82 386 292 366 194 344 132 286 229 362 320 246 59 52 236 44 24 75 249 100 166 397 248 70 403 369 316 478 407 448 396 287 213 452 467 189 197 21 260 154 223 419 174 141 398 319 117 285 368 149 89 263 364 274 441 7 140 130 5 269 387 177 88 81 470 18 161 12 459 165 131 127 408 110 176 210 418 34 280 354 410 45 442 186 147 265 62 440 13 252 325 146 111 23 156 457 436 36 4 125 484 306 188 394 49 491 332 352 8 279 499 497 17 55 136 152 196 378 90 250 65 6 190 60 173 56 266 208 267 257 46 406 463 360 435 172 58 241 315 375 389 272 454 137 310 449 69 22 273 414 184 284 434 395 382 214 275 427 447 67 374 42 270 168 460 357 336 19 451 238 54 217 33 300 388 276 211 251 495 243 95 219 296 227 392 494 481 318 84 390 450 200 334 384 247 335 74 486 305 216 345 11 57 405 372 29 3 358 118 293 294 104 180 86 122 61 202 404 198 225 39 170 327 343 302 473 143 105 359 298 183 329 377 76 393 72 342 307 237 456 80 385 51 129 297 438" | ./checker_Mac "112 78 283 489 277 428 337 425 416 218 474 30 426 244 187 443 222 153 150 338 381 232 437 2 331 323 175 412 261 317 195 309 133 468 401 445 106 383 71 101 35 465 259 475 485 128 371 155 402 193 483 9 102 164 226 493 113 94 446 303 347 10 498 215 228 271 162 98 114 79 93 179 199 163 254 490 220 126 14 367 379 231 160 68 107 278 472 330 321 413 120 256 288 108 399 25 340 43 391 37 242 205 1 121 341 324 492 482 27 209 139 103 488 314 429 461 40 116 124 422 15 32 203 235 73 500 134 480 145 28 233 373 424 85 178 171 353 346 409 299 289 87 313 50 350 191 144 119 182 487 83 439 41 444 224 148 221 430 169 53 151 349 333 64 351 363 421 479 400 466 496 48 77 181 99 411 239 63 258 185 96 115 123 38 234 453 240 158 264 477 471 339 431 301 138 322 20 356 16 308 253 167 423 268 361 291 420 455 469 281 282 157 433 290 380 462 135 476 311 370 142 376 458 97 109 31 201 192 47 230 464 206 415 245 295 159 66 328 312 255 432 91 365 262 304 348 417 212 207 26 355 92 326 204 82 386 292 366 194 344 132 286 229 362 320 246 59 52 236 44 24 75 249 100 166 397 248 70 403 369 316 478 407 448 396 287 213 452 467 189 197 21 260 154 223 419 174 141 398 319 117 285 368 149 89 263 364 274 441 7 140 130 5 269 387 177 88 81 470 18 161 12 459 165 131 127 408 110 176 210 418 34 280 354 410 45 442 186 147 265 62 440 13 252 325 146 111 23 156 457 436 36 4 125 484 306 188 394 49 491 332 352 8 279 499 497 17 55 136 152 196 378 90 250 65 6 190 60 173 56 266 208 267 257 46 406 463 360 435 172 58 241 315 375 389 272 454 137 310 449 69 22 273 414 184 284 434 395 382 214 275 427 447 67 374 42 270 168 460 357 336 19 451 238 54 217 33 300 388 276 211 251 495 243 95 219 296 227 392 494 481 318 84 390 450 200 334 384 247 335 74 486 305 216 345 11 57 405 372 29 3 358 118 293 294 104 180 86 122 61 202 404 198 225 39 170 327 343 302 473 143 105 359 298 183 329 377 76 393 72 342 307 237 456 80 385 51 129 297 438"
	@./$(NAME) "-1504871374 -1396318586 -711237121 66809901 -125222807 1279902556 1364048851 1730770651 546688206 1060793454 2031049450 -939069218 1969176780 596385154 553234972 -1156362468 587651684 1162339471 948482806 155118588 579607214 759816550 -1108378669 -1678650925 1844541558 -917180880 -1826553967 -698240550 133487683 -2117069015 -1068256448 -1793431569 -1338143189 285146441 487341194 1933361410 -85161526 950508095 2129068375 1143856459 682276982 291932115 -615280715 -1125291916 1785848918 1950189752 -656960818 -425633769 -1983773597 -707465538 -135202633 -1698871089 1617381102 899069744 474531467 -1614548754 2086004633 -1057481212 -66447742 -62887910 1211932549 -2085828481 1108908339 -600442891 142882622 1062346574 -334224729 285799455 1938830431 -1829591402 1359570829 1297117075 882508150 -1958183402 -1912484006 1049470639 668648160 1947824024 1008343788 761559254 -1649407906 1421082619 -1977810439 1328301490 1858634119 -1504184722 -498330801 235032934 -1457148777 1916673399 -322652678 -1221869833 -1869149841 -113763803 -1077318329 2036080937 1852392977 1257066284 -1402888064 390505982 -1963699895 -1432773538 -1534646562 -417286646 -1436652292 235822804 2024972959 -457090878 709810186 568733152 1731134479 173812689 1661648323 -904970702 -231981468 -616945926 1860225448 2110651850 -241949035 -123748047 1617093269 1387293706 -488751620 1844881141 850517109 -400778973 1359266310 -757243200 -1375451766 -425547300 -1151383500 781740730 -1321874142 -2017649867 -1597030430 -1067341172 -90040259 140269363 -1185025523 934657396 693352753 -331019879 -1114917496 -1567801169 -1597906297 1992660046 2385362 349325763 -335476174 121050881 -799125662 505018195 -1231099129 588637171 1127718253 1758649129 1541151926 -381890603 -232380978 -853479027 599935832 -1773232429 151958922 1596461620 -1995755624 -1566549645 -94640138 -1749377447 -612021750 -1874497274 -176976723 149838876 573817288 -1148164983 704546580 906972237 -1646000797 -644166850 489760672 -279073300 -1986318870 -999200798 101657945 -1676776404 -89848023 1049791609 -1011673637 1756141973 -2093796313 -1980469126 939942241 920598918 -1853991127 -813267656 1545391058 -1554353645 1239549523 1427120141 2146119266 179068409 1542172473 1474171205 -1653734469 360118774 273944063 -1140640525 1101540060 -431358258 -1545926274 -968150349 2128872330 2093258246 1607617879 544951750 -1495047982 80145700 666058200 410480338 -588474674 1486958002 -2106263740 1412703085 1762061607 -1891798814 739926485 -200529748 1670729105 1577559415 121697530 1437159337 -400275415 -2035820532 -1003079549 90875113 1586060505 -1076034589 2065661440 1581109589 745719569 -1190890684 -613584409 1679434113 -1713306162 -1968123791 -295535517 777367775 -246004432 1244204527 -216664235 -1361534767 1989374156 -1152729126 -715357182 1736685317 1729744808 1732534325 1949878670 -1434552509 1403571138 -2038680180 96492975 1297800932 -1981903225 -1515173081 -1632787003 -1120622061 776377405 1242617744 -1107181971 792905872 673424648 1335012584 237210556 -1976002273 2127766153 -472560579 -1924743528 1777899490 -921858250 1610114392 909594081 575735487 899061058 1861755154 56381586 -692707331 -1565029591 -1152609978 -1859276413 1055620677 40007831 -1582389071 247318685 -93011794 -302854050 2009980840 528277574 513989968 1285356761 -118060313 1421546163 -777767736 -189274881 1182200286 1101561751 -556230345 -913066296 1676322766 -454127757 1291203933 1694246301 -452079984 -932754361 86506145 1858467980 655282339 -2009868253 -1497636715 1357035688 -21345590 -838264142 1733577599 -1531018181 977881559 -473538291 -1791345897 441765164 -1939493794 1612779989 -1337068318 1478553950 123582975 643706142 928225027 443539901 -773588853 -1230884904 -1604060401 -638703935 -665807949 -1582309590 -413339806 -1568468012 1870079003 1567729020 297963987 -565018020 -1476080123 -1983561574 -11626433 -120369310 -2049580635 -1195625041 -1883787161 255799309 1391233144 1654006191 550249072 1655105990 1159893708 -1838625602 974770134 -1624991479 12798650 79900494 -437762549 685768660 -1747099524 1693971239 136304993 -993970920 631033300 1106740769 631212344 177476572 86742759 -1530793707 -949209451 1354562120 436319865 -498556658 -5796559 -142983075 1305084831 653501435 608071788 812288209 188706097 474319621 -958069483 -793906804 1762355931 1473279418 -1730331898 -826805614 -1990657927 636584922 306121098 -1122363506 -977775931 1005296868 -1968742442 748868336 2082036127 -1644559225 -1529266247 60498823 1411052732 1342545444 1781238537 -1493460179 14474781 880507074 -946871566 1447563060 1017832855 -1600279999 1838636756 1081040465 -59543566 -627425350 436034735 -1855644638 -1783389226 1383443381 -1672974792 1168121531 1151296486 -1177055671 16071 278542008 -1046547546 628152482 1268425248 -421117658 -332006523 -1087078877 -1211784723 -1672737307 2090773287 286963064 1691223969 -1362389525 -67922647 -1337306248 1051234444 353872230 -395793526 889737023 1034589740 758203881 770196465 984073897 1635692716 430086059 -1916514946 -979664569 829487047 -1221237609 1721981415 -745837627 1702448713 1459431098 -1724081890 -1250615130 1111772535 2047362434 2032499906 -2018188259 304493481 -171152685 1269388509 506990305 -387784377 205686148 -1643748207 -1704809041 270803533 1485464805 1445153129 1635469340 -1931663075 -2034690375 762126767 -378456601 -1250814786 -449051031 475799186 -1718300714 -1994095317 -1166607688 -342399861 1214723566 -13812916 872395334 314283649 1705923450 651723758 -1096599726 -1711964346" | ./checker_Mac "-1504871374 -1396318586 -711237121 66809901 -125222807 1279902556 1364048851 1730770651 546688206 1060793454 2031049450 -939069218 1969176780 596385154 553234972 -1156362468 587651684 1162339471 948482806 155118588 579607214 759816550 -1108378669 -1678650925 1844541558 -917180880 -1826553967 -698240550 133487683 -2117069015 -1068256448 -1793431569 -1338143189 285146441 487341194 1933361410 -85161526 950508095 2129068375 1143856459 682276982 291932115 -615280715 -1125291916 1785848918 1950189752 -656960818 -425633769 -1983773597 -707465538 -135202633 -1698871089 1617381102 899069744 474531467 -1614548754 2086004633 -1057481212 -66447742 -62887910 1211932549 -2085828481 1108908339 -600442891 142882622 1062346574 -334224729 285799455 1938830431 -1829591402 1359570829 1297117075 882508150 -1958183402 -1912484006 1049470639 668648160 1947824024 1008343788 761559254 -1649407906 1421082619 -1977810439 1328301490 1858634119 -1504184722 -498330801 235032934 -1457148777 1916673399 -322652678 -1221869833 -1869149841 -113763803 -1077318329 2036080937 1852392977 1257066284 -1402888064 390505982 -1963699895 -1432773538 -1534646562 -417286646 -1436652292 235822804 2024972959 -457090878 709810186 568733152 1731134479 173812689 1661648323 -904970702 -231981468 -616945926 1860225448 2110651850 -241949035 -123748047 1617093269 1387293706 -488751620 1844881141 850517109 -400778973 1359266310 -757243200 -1375451766 -425547300 -1151383500 781740730 -1321874142 -2017649867 -1597030430 -1067341172 -90040259 140269363 -1185025523 934657396 693352753 -331019879 -1114917496 -1567801169 -1597906297 1992660046 2385362 349325763 -335476174 121050881 -799125662 505018195 -1231099129 588637171 1127718253 1758649129 1541151926 -381890603 -232380978 -853479027 599935832 -1773232429 151958922 1596461620 -1995755624 -1566549645 -94640138 -1749377447 -612021750 -1874497274 -176976723 149838876 573817288 -1148164983 704546580 906972237 -1646000797 -644166850 489760672 -279073300 -1986318870 -999200798 101657945 -1676776404 -89848023 1049791609 -1011673637 1756141973 -2093796313 -1980469126 939942241 920598918 -1853991127 -813267656 1545391058 -1554353645 1239549523 1427120141 2146119266 179068409 1542172473 1474171205 -1653734469 360118774 273944063 -1140640525 1101540060 -431358258 -1545926274 -968150349 2128872330 2093258246 1607617879 544951750 -1495047982 80145700 666058200 410480338 -588474674 1486958002 -2106263740 1412703085 1762061607 -1891798814 739926485 -200529748 1670729105 1577559415 121697530 1437159337 -400275415 -2035820532 -1003079549 90875113 1586060505 -1076034589 2065661440 1581109589 745719569 -1190890684 -613584409 1679434113 -1713306162 -1968123791 -295535517 777367775 -246004432 1244204527 -216664235 -1361534767 1989374156 -1152729126 -715357182 1736685317 1729744808 1732534325 1949878670 -1434552509 1403571138 -2038680180 96492975 1297800932 -1981903225 -1515173081 -1632787003 -1120622061 776377405 1242617744 -1107181971 792905872 673424648 1335012584 237210556 -1976002273 2127766153 -472560579 -1924743528 1777899490 -921858250 1610114392 909594081 575735487 899061058 1861755154 56381586 -692707331 -1565029591 -1152609978 -1859276413 1055620677 40007831 -1582389071 247318685 -93011794 -302854050 2009980840 528277574 513989968 1285356761 -118060313 1421546163 -777767736 -189274881 1182200286 1101561751 -556230345 -913066296 1676322766 -454127757 1291203933 1694246301 -452079984 -932754361 86506145 1858467980 655282339 -2009868253 -1497636715 1357035688 -21345590 -838264142 1733577599 -1531018181 977881559 -473538291 -1791345897 441765164 -1939493794 1612779989 -1337068318 1478553950 123582975 643706142 928225027 443539901 -773588853 -1230884904 -1604060401 -638703935 -665807949 -1582309590 -413339806 -1568468012 1870079003 1567729020 297963987 -565018020 -1476080123 -1983561574 -11626433 -120369310 -2049580635 -1195625041 -1883787161 255799309 1391233144 1654006191 550249072 1655105990 1159893708 -1838625602 974770134 -1624991479 12798650 79900494 -437762549 685768660 -1747099524 1693971239 136304993 -993970920 631033300 1106740769 631212344 177476572 86742759 -1530793707 -949209451 1354562120 436319865 -498556658 -5796559 -142983075 1305084831 653501435 608071788 812288209 188706097 474319621 -958069483 -793906804 1762355931 1473279418 -1730331898 -826805614 -1990657927 636584922 306121098 -1122363506 -977775931 1005296868 -1968742442 748868336 2082036127 -1644559225 -1529266247 60498823 1411052732 1342545444 1781238537 -1493460179 14474781 880507074 -946871566 1447563060 1017832855 -1600279999 1838636756 1081040465 -59543566 -627425350 436034735 -1855644638 -1783389226 1383443381 -1672974792 1168121531 1151296486 -1177055671 16071 278542008 -1046547546 628152482 1268425248 -421117658 -332006523 -1087078877 -1211784723 -1672737307 2090773287 286963064 1691223969 -1362389525 -67922647 -1337306248 1051234444 353872230 -395793526 889737023 1034589740 758203881 770196465 984073897 1635692716 430086059 -1916514946 -979664569 829487047 -1221237609 1721981415 -745837627 1702448713 1459431098 -1724081890 -1250615130 1111772535 2047362434 2032499906 -2018188259 304493481 -171152685 1269388509 506990305 -387784377 205686148 -1643748207 -1704809041 270803533 1485464805 1445153129 1635469340 -1931663075 -2034690375 762126767 -378456601 -1250814786 -449051031 475799186 -1718300714 -1994095317 -1166607688 -342399861 1214723566 -13812916 872395334 314283649 1705923450 651723758 -1096599726 -1711964346"

leaks: $(NAME)
	@echo "\n---TESTING LEAKS---"
	leaks --atExit -q -- ./$(NAME) 1 3 4 1 2
	leaks --atExit -q -- ./$(NAME) 1 3 4 1 a
	leaks --atExit -q -- ./$(NAME) 5 3 4 1 2

test_bonus: $(NAME) $(BONUS) $(LIBFT)
	@echo "\n---TESTING BONUS---"
	@echo "\nInvalid inputs:"
	./$(BONUS) 1 2 1
	./$(BONUS) 1 2 2147483648
	./$(BONUS) -2147483649 1 2
	./$(BONUS) 1 2 a
	./$(BONUS) 1 2 +3
	./$(BONUS) 1 2 3a
	@echo "\nFunction:"
	@./$(NAME) "5 4 2 1 3" | ./$(BONUS) "5 4 2 1 3"
	@./$(NAME) "2 1 3 5 4" | ./$(BONUS) "2 1 3 5 4"
	@./$(NAME) "3 2 5 4 1" | ./$(BONUS) "3 2 5 4 1"
	@./$(NAME) "3 5 1 4 2" | ./$(BONUS) "3 5 1 4 2"
	@./$(NAME) "5 4 2 1 3" | ./$(BONUS) "5 4 2 1 3"
	@./$(NAME) "2 1 3 5 4" | ./$(BONUS) "2 1 3 5 4"
	@./$(NAME) "3 2 5 4 1" | ./$(BONUS) "3 2 5 4 1"
	@./$(NAME) "3 5 1 4 2" | ./$(BONUS) "3 5 1 4 2"
	@./$(NAME) "1006904419 -1180256924 -1509642107 -969477600 -1102846459" | ./$(BONUS) "1006904419 -1180256924 -1509642107 -969477600 -1102846459"