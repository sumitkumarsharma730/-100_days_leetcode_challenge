class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2){
            return true;
        }
        for(int Y1 = y1; Y1 <= y2; Y1++){
            double  dis = sqrt( (x1-xCenter)*(x1-xCenter) + (Y1-yCenter)*(Y1-yCenter) );
            dis = min( dis, sqrt( (x2-xCenter)*(x2-xCenter) + (Y1-yCenter)*(Y1-yCenter) ) );
            if(dis <= radius){
                return true;
            }
        }
        for(int X1 = x1; X1 <= x2; X1++){
            double dis = sqrt( (X1-xCenter)*(X1-xCenter) + (y1-yCenter)*(y1-yCenter) );
            dis = min( dis, sqrt( (X1-xCenter)*(X1-xCenter) + (y2-yCenter)*(y2-yCenter) ) );
            if(dis <= radius){
                return true;
            }
        }
        return false;
    }
};