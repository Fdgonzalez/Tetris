#include "grid.h"

bool isOccupied(point p) {
    return ! (grid[p.x][p.y].color.r == 255 && grid[p.x][p.y].color.g == 255 && grid[p.x][p.y].color.b == 255);
}
bool outsideBounds(point p){
    return !(p.x < BOARDW && p.x >= 0 && p.y < BOARDH && p.y >= 0);
}
void createGrid(){
    int playAreaWidth = (int) (0.48 * WIDTH);
    int playAreaHeight = (int) (0.96 * HEIGHT);
    int playAreaStartW = (int) (0.02 * WIDTH);
    int playAreaStartH = playAreaStartW;
    int stepX = playAreaWidth / BOARDW;
    int stepY = playAreaHeight / BOARDH;
    int blockGaps = 1;
    for(int i=0;i<BOARDW;i++){
        for(int j=0;j<BOARDH;j++){
            grid[i][j].rect.x = i * stepX + playAreaStartW;
            grid[i][j].rect.y = j * stepY + playAreaStartH;
            grid[i][j].rect.h = stepY - blockGaps;
            grid[i][j].rect.w = stepX - blockGaps;
            grid[i][j].color = WHITE;
        }
    }
}
void deleteLine(int i){
    for(int k=0;(i-k) > 0;k++){
        for(int x=0;x<BOARDW;x++){
            grid[x][i-k].color = grid[x][i-(k+1)].color;
        }
    }
}
//return lines cleared
int updateGrid(){
    int deleted = 0;
    //scan each line and delete it if it's full
    for(int i=0;i<BOARDH;i++){
        bool delete = true;
        for(int j=0;j<BOARDW;j++){
            if(!isOccupied((point){j,i}))
                delete = false;
        }
        if(delete){
            deleted++;
            deleteLine(i);
        }
    }
    return deleted;
}
void drawGrid(){
    for(int i=0;i<BOARDW;i++){
        for(int j=0;j<BOARDH;j++){
            drawBlock(grid[i][j]);
        }
    }
}