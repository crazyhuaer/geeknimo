/**
 * 			Dododo
 *
 * */
class Value1 {
    int x,y;
    Value1(int x,int y) {
        this.x = x;
        this.y = y;
    }
}

class Value2 extends Value1 {
    Value2(int a,int b) {
        super(a,b);
        this.x = 50;
    }
}

public class first {

    int x;
    String name;
    static int count = 0;

    public first(String name) {
        this.count++;
        this.name = name;
        //this.show();
    }

    static public void test_show() {
        count = 55;
    }

    private void show() {
        System.out.println(this.count);
    }

    public static void main(String args[]) {
        /**
        //System.out.println(args[0]+":You are welcome!");
        first h = new first("Jone");
        //h.show();
        int m = 30;
        byte B = 20;
        boolean b = false;
        if(b){
        	m = 50 + B;
        }else{
        	m = 70 + B;
        }
        test_show();
        first h1 = new first("Jone");
        h.show();
        h1.show();
        //System.out.println(m);
        */
        //Super Test
        Value1 v1 = new Value1(20,30);
        Value2 v2 = new Value2(10,5);
        int t = v2.x + v2.y;
        System.out.println(v2.x+" "+v2.y+" "+t);
    }
}