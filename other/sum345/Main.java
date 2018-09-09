import java.util.ArrayList;

class Main{
  public static void main(String[] args) {
    ArrayList<Integer> arr = new ArrayList<>();
    for(int i = 0; i < 100; i++) {
      arr.add(calc(arr, i));
    }

    for(int i = 0; i < arr.size(); i++) {
      System.out.printf("%3d:%20d\n",i,arr.get(i));
    }
  }

  static int calc(ArrayList<Integer> arr, int x) {
    int result = 0;
    for(int i = 3; i <= 5; i++) {
      int before = x-i;
      if(before<0) break;
      int value = arr.get(before);
      if(value==0 && before==0) result++;
      else result += value;
    }
    return result;
  }
}
