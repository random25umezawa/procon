import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args) throws Exception{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String[] wh = reader.readLine().split(" ",0);
		int w = Integer.parseInt(wh[0]);
		int h = Integer.parseInt(wh[1]);

		int[] costX = new int[w];
		int[] costY = new int[h];

		for(int i = 0; i < w; i++) {
			costX[i] = Integer.parseInt(reader.readLine());
		}
		for(int i = 0; i < h; i++) {
			costY[i] = Integer.parseInt(reader.readLine());
		}

		Arrays.sort(costX);
		Arrays.sort(costY);

		int wIndex = 0;
		int hIndex = 0;

		long result = 0;

		for(;;) {
			if(wIndex>=costX.length && hIndex>=costY.length) break;
			if(hIndex<costY.length && (wIndex>=costX.length || costX[wIndex] > costY[hIndex])) {
				result += (long)costY[hIndex] * (long)(w-wIndex+1);
				hIndex++;
			}else {
				result += (long)costX[wIndex] * (long)(h-hIndex+1);
				wIndex++;
			}
			//System.out.println(result);
		}

		System.out.println(result);
	}
}
