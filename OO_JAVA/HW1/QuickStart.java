class list {
    list(){ count = 0;}
    list next, back;
    char a;
    int count;
}




class QuickStart {
    public static void main(final String[] args) {
        list head, temp, o;

        int j=0, count=0;
        o = new list();
        head = o;
        if (args.length > 0)
        {
            for (int i=0; i<args.length; i++)
            {
                for (j=0; j<args[i].length(); j++)
                {
                    o.next = new list();
                    o.next.back = o;
                    o.a = args[i].charAt(j);
                    o.count = 1;
                    o = o.next;
                    count++;
                }
            }
        }
        int countNew, k=0;
        o = head;
        for (int i=0; i<count; i++)
        {
            temp = o.next;
            countNew = count;
            for (k=i+1; k<countNew; k++)
            {
                if (temp.a == o.a)
                {
                    o.count = o.count + 1;
                    temp.back.next = temp.next;
                    count--;
                    temp = temp.next;
                }
                else
                {
                    temp = temp.next;
                }
            }
            o = o.next;
        }

        o = head;
        for (int i=0; i<count; i++)
        {
            System.out.println(o.a + "-" + o.count);
            o = o.next;
        }
    }
}
