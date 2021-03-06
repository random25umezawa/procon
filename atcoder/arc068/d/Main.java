import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		HashSet<Integer> set = new HashSet<>(n);
		int result = 0;
		for(String _s : reader.readLine().split(" ")) {
			int _num = Integer.parseInt(_s);
			if(set.contains(_num)) {
				result++;
			}else {
				set.add(_num);
			}
		}
		System.out.println(n-(result+((result%2==1)?1:0)));
	}
}
