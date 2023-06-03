public class WordMatch
{
    private String secret;

    public WordMatch(String word)
    {
        secret = word;
    }

    public int scoreGuess(String guess)
    {
        int slen = secret.length();
        int len = guess.length();
        int cnt = 0;
        
        for(int i = 1; i <= slen - len; i ++)
        {
            if(secret.substring(i, i + len).equals(guess))
            {
                cnt ++;
            }
        }

        int ans = cnt * len * len;

        return ans;
    }

    public String findBetterGuesses(String guess1, String guess2)
    {
        int g1 = scoreGuess(guess1);
        int g2 = scoreGuess(guess2);

        if(g1 < g2)
            return guess1;

        if(g1 > g2)
            return guess2;

        if(guess1.compareTo(guess2))
            return guess1;
        
        return guess2;
    }
}