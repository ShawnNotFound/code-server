public boolean isLevelTrailSegment(int start, int end)
{
    int maxn = markers[start], minn = markers[start];
    for(int i = start; i <= end; i ++)
    {
        if(markers[i] > maxn)
            maxn = markers[i];
        if(markers[i] < minn)
            minn = markers[i];

        if(maxn - minn > 10)
            return false;
    }
    
    return true;
}

public boolean isDifficult()
{
    int cnt = 0;
    for(int i = 1; i < markers.length(); i ++)
    {
        int diff = markers[i] > markers[i - 1] ? markers[i] - markers[i - 1] : markers[i - 1] - markers[i];

        if(diff >= 30)
            cnt ++;
    }

    if(cnt >= 3)
        return true;
    else    
        return false;
}