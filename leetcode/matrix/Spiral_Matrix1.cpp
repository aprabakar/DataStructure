class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int i =0 ,j = 0 , count= 0;
        vector<int> final_list;
        
         if(matrix.size() < 1)
            return final_list;
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int top,bottom,left,right;
        
        top = 0;
        left = 0;
        bottom = rows-1;
        right = columns-1;
        
        bool isTop=true, isBottom =false, isRight = false, isLeft = false;
        
        while(count <= rows*columns){
            
            // cout<< "top : " << top << endl
            //     << "bottom : " << bottom << endl
            //     << "right : " << right << endl
            //     << "left : " << left << endl
            //     << "i : " << i << endl
            //     << "j : " << j << endl
            //     << "count : " << count << endl;
            
            //Right Traversal
            while(j <= right && isTop){
                isRight = true;
                final_list.push_back(matrix[i][j]);
                j++;
                count++;
            }
            
            //Prepare for next bottom traversal
            right--;
            top++;
            isTop = false;
            j--;
            i++;
            
            // Previous Right traversal is done?
            if(!isRight){
                break;
            }
            
            //Bottom Traversal
            while(i <= bottom){
                isBottom = true;
                final_list.push_back(matrix[i][j]);
                i++;
                count++;
            }
            
            //Prepare for next left traversal
            bottom--;
            isRight = false;
            i--;
            j--;
            
            // Previous bottom traversal is done?
            if(!isBottom){
                break;
            }
            
            //Left Traversal
            while(j >= left){
                isLeft = true;
                final_list.push_back(matrix[i][j]);
                j--;
                count++;
            }
            
            //Prepare for next top traversal
            left++;
            isBottom = false;
            j++;
            i--;
            
            // Previous left traversal is done?
            if(!isLeft){
                break;
            }
            
            //Top Traversal
            while(i >= top){
                isTop = true;
                final_list.push_back(matrix[i][j]);
                i--;
                count++;
            }
            
            //Prepare for next right traversal
            isLeft = false;
            i++;
            j++;
            
            // Previous top traversal is done?
            if(!isTop){
                break;
            }
            //cout<< "<< ------- loop ------>>" << endl;
        }
        return final_list;
    }
};
