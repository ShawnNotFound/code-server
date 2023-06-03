public class APLine
{
    private int[] line;

    public APLine(int a, int b, int c)
    {
        line[1] = a;
        line[2] = b;
        line[3] = c;
    }

    public double getSlope()
    {
        return  ( - line[1] / line[2]);
    }

    public boolean isOnLine(int aa, int bb)
    {
        if(!(aa * line[1] + bb * line[2] + line[3]))
            return true;

        return false;
    }
}