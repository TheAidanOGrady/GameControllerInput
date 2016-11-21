/******************************************************************************
*
 * @file    view.h
 * @author  Aidan O'Grady
 * @date    2016-11-11
 * @version 0.1
 *
 * Contains all the variables and functions required for the view.
 *
 ******************************************************************************/
#ifndef VIEW_H
#define VIEW_H

/**
 * Attempts to create the window.
 *
 * @return true if creation successful, otherwise returns false.
 */
bool view_init();

/**
 * Clears the current screen.
 */
void clear_render();

/**
 * Renders the input text and prompt.
 *
 * @param input the input to be displayed
 * @param prompt the prompt that is to be displayed
 */
void render_input(char input[], char prompt[]);


/**
 * Renders a line underneath characters that are not correct.
 *
 * @param pos the position of the incorrect character in string
 * @param length the length of the string the user has input
 */
void render_line(int pos, int length);

/**
 * The renders the given text, giving it the colour provided.
 *
 * @param text the text to render
 * @param colour the colour of the text
 */
void render_text(char text[], SDL_Color colour);

/**
 * Renders a key with the given position and cursor state.
 *
 * @param x the x position on matrix
 * @param y the y position on matrix
 * @param key the character to be rendered
 * @param mode the mode this key is in (see Mode in Keyboard.h)
 */
void render_key(int x, int y, char key, int mode);

/**
 * Refreshes the display to match current situation.
 */
void repaint();

/**
 * Destroys everything relating to view.
 */
void view_close();

#endif // VIEW_H