public class CombinedTable
{
    private SingleTable t1;
    private SingleTable t2;

    public CombinedTable(SingleTable a, SingleTable b)
    {
        t1 = a;
        t2 = b;
    }

    public boolean canSeat(int x)
    {
        int maxn = t1.getNumSeats() + t2.getNumSeats() - 2;

        if(x <= maxn)
            return true;
        else
            return false;
    }

    public double getDesirability()
    {
        int h1 = t1.getHeight();
        int h2 = t2.getHeight();

        double d1 = t1.getViewQuality();
        double d2 = t2.getViewQuality();

        if (h1 == h2)
            return (d1 + d2) / 2;

        else
            return (d1 + d2) / 2 + 10;
    }
}