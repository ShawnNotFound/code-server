public static boolean isNonZeroRow(int[][] array2D, int r)
{
    for(int i = 0; i < array2D[0].size(); i ++)
    {
        if(!array2D[r][i])  
            return false;
    }

    return true;
}

public static int[][] resize(int[][] array2D)
{

    int num = array2D.numNonZeroRow();

    int[][] ans = new int[num][array2D[0].length()];

    int cnt = 0, i = 0;
    while(cnt <= num)
    {
        if(isNonZeroRow(array2D, i))
        {
            cnt ++;
            for(int j = 0; j < array2D[0].length(); j ++)
                ans[cnt][j] = array2D[i][j];
        }
        i ++;
    }

    return ans;
}