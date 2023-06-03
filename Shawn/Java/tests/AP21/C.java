public void addMembers(String[] names, int gradYear) 
{
    for(String name : names)
    {
        MemberInfo mem = new MemberInfo(name, gradYear, true);

        memberList.add(mem);
    }
}

public ArrayList<MemberInfo> removeMembers(int year)
{
    ArrayList<MemberInfo> ans = new ArrayList<MemberInfo>();

    for(int i = 0; i < memberList.size(); i ++)
    {
        int y = memberList.get(i).getGradYear();
        boolean g = memberList.get(i).inGoodStanding();
        if(y <= year)
        {
            if(g)
                ans.add(memberList.get(i));
            
            memberList.remove(i);
        }
    }

    return ans;
}

// public int getGradYear() 
// public boolean inGoodStanding() 