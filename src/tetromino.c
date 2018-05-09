#include <sys/time.h>
#include "tetromino.h"
#include "defs.h"
#include "grid.h"

tetromino *current;
tetromino *ghost;
int bag[] = {0,1,2,3,4,5,6};
uint8_t currentT = 0;

bool swapped;
char swap; // the type of tetromino that's stored
void lockTetromino(tetromino *t) {
    t->falling = false;
    if (t == ghost)
        return;
    grid[t->a.x][t->a.y].color = t->color;
    grid[t->b.x][t->b.y].color = t->color;
    grid[t->c.x][t->c.y].color = t->color;
    grid[t->d.x][t->d.y].color = t->color;
}
void shuffle(int *array, size_t n) { // stolen from stackExchange user Nomadiq
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int usec = tv.tv_usec;
    srand48(usec);


    if (n > 1) {
        size_t i;
        for (i = n - 1; i > 0; i--) {
            size_t j = (unsigned int) (drand48()*(i+1));
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}
void lockCurrent(){
    lockTetromino(current);
}
void initializeBag(){
    shuffle(bag,7);
}
tetromino *spawnI() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 0};
    point b = (point) {mid / 2 - 1, 0};
    point c = (point) {mid / 2, 0};
    point d = (point) {mid / 2 + 1, 0};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = LBLUE;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'I';
    ret->falling = true;

    return ret;
}

tetromino *spawnJ() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 0};
    point b = (point) {mid / 2 - 1, 0};
    point c = (point) {mid / 2, 0};
    point d = (point) {mid / 2, 1};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = ORANGE;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'J';
    return ret;
}

tetromino *spawnL() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 1};
    point b = (point) {mid / 2 - 2, 0};
    point c = (point) {mid / 2 - 1, 0};
    point d = (point) {mid / 2, 0};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = BLUE;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'L';
    ret->falling = true;

    return ret;
}

tetromino *spawnS() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 1};
    point b = (point) {mid / 2 - 1, 1};
    point c = (point) {mid / 2 - 1, 0};
    point d = (point) {mid / 2, 0};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = GREEN;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'S';
    ret->falling = true;
    return ret;
}

tetromino *spawnT() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 0};
    point b = (point) {mid / 2 - 1, 0};
    point c = (point) {mid / 2, 0};
    point d = (point) {mid / 2 - 1, 1};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = VIOLET;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'T';
    ret->falling = true;

    return ret;
}

tetromino *spawnO() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2, 0};
    point b = (point) {mid / 2 + 1, 0};
    point c = (point) {mid / 2, 1};
    point d = (point) {mid / 2 + 1, 1};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = YELLOW;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'O';
    ret->falling = true;

    return ret;
}

tetromino *spawnZ() {
    int mid = (int) BOARDW / 2;
    point a = (point) {mid / 2 - 2, 0};
    point b = (point) {mid / 2 - 1, 0};
    point c = (point) {mid / 2 - 1, 1};
    point d = (point) {mid / 2, 1};
    tetromino *ret = malloc(sizeof(tetromino));
    ret->color = RED;
    ret->a = a;
    ret->b = b;
    ret->c = c;
    ret->d = d;
    ret->rotation = 1;
    ret->type = 'Z';
    ret->falling = true;

    return ret;
}

//Return 1 if block got locked, 0 otherwise
int gravity(tetromino *t) {
    tetromino prev = *t;
    if (t->a.y + 1 < BOARDH && t->b.y + 1 < BOARDH && t->c.y + 1 < BOARDH && t->d.y + 1 < BOARDH) {
        t->a.y++;
        t->b.y++;
        t->c.y++;
        t->d.y++;
    } else {
        lockTetromino(t);
        return 1;
    }
    if (tetrominoCollides(t)) {
        //set current tetromino to previous values and lock it
        memcpy(t, &prev, sizeof(tetromino));
        lockTetromino(t);
        return 1;
    }
    return 0;
}

bool currentOutsideBounds() {
    return outsideBounds(current->a) || outsideBounds(current->b) || outsideBounds(current->c) ||
           outsideBounds(current->d);
}

void spawnRandomTetromino() {
    if (current != NULL)
        free(current);
    if(currentT > 6){
        currentT = 0;
        initializeBag();
    }

    switch (bag[currentT++]) {
        case 0:
            current = spawnO();
            break;
        case 1:
            current = spawnJ();
            break;
        case 2:
            current = spawnL();
            break;
        case 3:
            current = spawnS();
            break;
        case 4:
            current = spawnT();
            break;
        case 5:
            current = spawnI();
            break;
        case 6:
            current = spawnZ();
            break;
    }
}
void spawnTetromino(char type){
    switch(type){
        case 'O':
            current = spawnO(); break;
        case 'J':
            current = spawnJ(); break;
        case 'L':
            current = spawnL(); break;
        case 'S':
            current = spawnS(); break;
        case 'T':
            current = spawnT(); break;
        case 'I':
            current = spawnI(); break;
        case 'Z':
            current = spawnZ(); break;
    }
}

void updateGhost() {
    if(ghost == NULL)
        ghost = malloc(sizeof(tetromino));
    memcpy(ghost, current, sizeof(tetromino));
    ghost->color = GHOSTCOLOR;
    while (gravity(ghost) != 1);
}

void drawTetromino(tetromino *t) {
    drawBlockWithColor(grid[t->a.x][t->a.y], t->color);
    drawBlockWithColor(grid[t->b.x][t->b.y], t->color);
    drawBlockWithColor(grid[t->c.x][t->c.y], t->color);
    drawBlockWithColor(grid[t->d.x][t->d.y], t->color);
}
void moveRight(){
    tetromino prev = *current;
    current->a.x++;
    current->b.x++;
    current->c.x++;
    current->d.x++;
    if(currentOutsideBounds() || tetrominoCollides(current))
        memcpy(current, &prev, sizeof(tetromino));
}

void moveLeft() {
    tetromino prev = *current;
    current->a.x--;
    current->b.x--;
    current->c.x--;
    current->d.x--;
    if (currentOutsideBounds() || tetrominoCollides(current))
        memcpy(current, &prev, sizeof (tetromino));
}

void rotate() {//Nintendo rotation like, no wall kick
    tetromino prev = *current;
    switch (current->type) {
        case 'I':
            if (current->rotation == 1) {
                current->a.x = current->c.x;
                current->b.x = current->c.x;
                current->d.x = current->c.x;
                current->a.y = current->c.y - 2;
                current->b.y = current->c.y - 1;
                current->d.y = current->c.y + 1;
                current->rotation = 2;

            } else {
                current->a.x = current->c.x - 2;
                current->b.x = current->c.x - 1;
                current->d.x = current->c.x + 1;
                current->a.y = current->c.y;
                current->b.y = current->c.y;
                current->d.y = current->c.y;
                current->rotation = 1;
                //TODO: Rewrite this
            }
            break;
        case 'O':
            break;
        case 'J':
            switch (current->rotation) {
                case 1:
                    current->a.x = current->b.x;
                    current->a.y--;
                    current->c.x = current->b.x;
                    current->c.y++;
                    current->d.x -= 2;
                    current->rotation = 2;
                    break;
                case 2:
                    current->a.x++;
                    current->a.y++;
                    current->c.x--;
                    current->c.y--;
                    current->d.y -= 2;
                    current->rotation = 3;
                    break;
                case 3:
                    current->d.x += 2;
                    current->c.x++;
                    current->c.y--;
                    current->a.y++;
                    current->a.x--;
                    current->rotation = 4;
                    break;
                case 4:
                    current->a.x--;
                    current->a.y--;
                    current->c.x++;
                    current->c.y++;
                    current->d.y += 2;
                    current->rotation = 1;
                    break;
            }
            break;
        case 'L':
            switch (current->rotation) {
                case 1:
                    current->a.y -= 2;
                    current->b.x++;
                    current->b.y--;
                    current->d.x--;
                    current->d.y++;
                    current->rotation = 2;
                    break;
                case 2:
                    current->a.x += 2;
                    current->b.x++;
                    current->b.y++;
                    current->d.x--;
                    current->d.y--;
                    current->rotation = 3;
                    break;
                case 3:
                    current->a.y += 2;
                    current->b.x--;
                    current->b.y++;
                    current->d.y--;
                    current->d.x++;
                    current->rotation = 4;
                    break;
                case 4:
                    current->a.x -= 2;
                    current->b.x--;
                    current->b.y--;
                    current->d.x++;
                    current->d.y++;
                    current->rotation = 1;
                    break;
            }
            break;
        case 'S':
            switch (current->rotation) {
                case 1:
                    current->a.x++;
                    current->a.y -= 2;
                    current->b.y--;
                    current->c.x++;
                    current->d.y++;
                    current->rotation = 2;
                    break;
                case 2:
                    current->a.x--;
                    current->a.y += 2;
                    current->b.y++;
                    current->c.x--;
                    current->d.y--;
                    current->rotation = 1;
                    break;
            }
            break;
        case 'T':
            switch (current->rotation) {
                case 1:
                    current->a.x++;
                    current->a.y--;
                    current->c.x--;
                    current->c.y++;
                    current->d.x--;
                    current->d.y--;
                    current->rotation = 2;
                    break;
                case 2:
                    current->a.x++;
                    current->a.y++;
                    current->c.x--;
                    current->c.y--;
                    current->d.x++;
                    current->d.y--;
                    current->rotation = 3;
                    break;
                case 3:
                    current->a.x--;
                    current->a.y++;
                    current->c.x++;
                    current->c.y--;
                    current->d.x++;
                    current->d.y++;
                    current->rotation = 4;
                    break;
                case 4:
                    current->c.x++;
                    current->c.y++;
                    current->a.x--;
                    current->a.y--;
                    current->d.x--;
                    current->d.y++;
                    current->rotation = 1;
                    break;
            }
            break;
        case 'Z':
            switch (current->rotation) {
                case 1:
                    current->a.x += 2;
                    current->a.y--;
                    current->b.x++;
                    current->c.y--;
                    current->d.x--;
                    current->rotation = 2;
                    break;
                case 2:
                    current->a.x -= 2;
                    current->a.y++;
                    current->b.x--;
                    current->c.y++;
                    current->d.x++;
                    current->rotation = 1;
                    break;
            }
            break;
    }
    if (currentOutsideBounds())
        moveRight();
    if (currentOutsideBounds()) {
        moveLeft();
        moveLeft();
    }
    if (currentOutsideBounds() || tetrominoCollides(current))
        memcpy(current, &prev, sizeof(tetromino));
}

void drawCurrent() {
    drawTetromino(current);
}

void drawGhost() {
    drawTetromino(ghost);
}

void currentGravity() {
    gravity(current);
}
void dropCurrent(){
    while(gravity(current) != 1);
}
void swapCurrent(){
    if(!swapped) {
        swapped = true;
        char temp = 0;
        if (swap == NULL) {
            swap = current->type;
            spawnRandomTetromino();
        } else {
            temp = current->type;
            spawnTetromino(swap);
            swap = temp;
        }
    }
}
//return -1 if lost
int updateCurrent(){
    if(! (current->falling)){
        swapped = false;
        spawnRandomTetromino();
        if(tetrominoCollides(current)){
            return -1;
        }
    }
    return 0;
}

bool tetrominoCollides(tetromino *t) {
    return isOccupied(t->a) || isOccupied(t->b) || isOccupied(t->c) || isOccupied(t->d);
}
