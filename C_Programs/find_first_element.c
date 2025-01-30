for (int row = 0; row < MAX_ROWS; row++) {
        int column = 0;
        int is_empty = 1;  // Flag to check if the line is empty

        // Check if the current line has any non-null characters
        while (array[row][column] != '\0') {
            if (array[row][column] != ' ' && array[row][column] != '\t') {
                is_empty = 0;  // Line is not empty if there's a non-space character
                break;
            }
            column++;
        }

        // Only print the line if it's not empty
        if (!is_empty) {
    
