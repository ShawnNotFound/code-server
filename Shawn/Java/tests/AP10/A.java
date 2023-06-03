public int getTotalBoxes()
{
    int TotalBoxes = 0;
    for(CookieOrder c : orders)
    {
        TotalBoxes += c.getNumBoxes();
    }

    return TotalBoxes;
}

public int removeVariety(String cookieVar)
{
    int ans = 0;

    for(int i = 0; i < orders.size(); i ++)
    {
        if(orders.get(i).getVariety().equal(cookieVar))
        {
            ans ++;
            orders.remove(i);
        }
    }

    return ans;
}
