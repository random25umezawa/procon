import java.util.*;

class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		while(true) {

			int n = scan.nextInt();
			int m = scan.nextInt()-1;
			int l = scan.nextInt()-1;

			if(n==0) break;

			//lineとpointを入力

			ArrayList<Line> lines = new ArrayList<>();
			ArrayList<Point> points = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				int x = scan.nextInt();
				int y = scan.nextInt();
				int a = scan.nextInt();
				int r = scan.nextInt();
				for(int j = 0; j < 5; j++) {
					double x1 = x+r*Math.sin(-Math.toRadians(a+j*72));
					double y1 = y+r*Math.cos(-Math.toRadians(a+j*72));
					double x2 = x+r*Math.sin(-Math.toRadians(a+(j+1)*72));
					double y2 = y+r*Math.cos(-Math.toRadians(a+(j+1)*72));

					lines.add(new Line(x1,y1,x2,y2));
					points.add(new Point(x1,y1));
					//points.push(new Point(x2,y2));
				}
			}

			//各☆間の最短距離グラフを作る
			//線と点の距離は垂線がかけるかどうかで分ける必要アリ
			double[][] graph = new double[n][n];

			for(int i = 0; i < n; i++) {
				for(int j = i; j < n; j++) {
					double minLength = 999999999;
					for(int k = 0; k < 5; k++) {
						for(int p = 0; p < 5; p++) {
							minLength = Math.min(
								minLength,
								lines.get(i*5+k).getPointLength(points.get(j*5+p))
							);
						}
					}
					graph[i][j] = minLength;
					graph[j][i] = minLength;
				}
			}
			/*
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					System.out.print(graph[i][j]+",");
				}
				System.out.println();
			}
			*/

			//あとはダイクストラ
			int startPos = m;
			double[] minArr = new double[n];
			boolean[] flagArr = new boolean[n];
			while(true) {
				flagArr[startPos] = true;
				int minIndex = -1;
				double minLength = 999999999.9;
				for(int i = 0; i < n; i++) {
					if(!flagArr[i]) {
						if(graph[startPos][i]<minLength) {
							minLength = graph[startPos][i];
							minIndex = i;
						}
					}
				}
				if(minIndex==-1) break;
				minArr[minIndex] = minArr[startPos]+minLength;
				startPos = minIndex;
			}

			System.out.println(minArr[l]);
		}
	}
}

class Line{
	double x1,y1,x2,y2;
	Line(double _x1, double _y1, double _x2, double _y2) {
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}
	double getPointLength(Point _point) {
		//return 5.0;
		double a = x1;
		double b = y1;
		double c = x2;
		double d = y2;
		double e = _point.x;
		double f = _point.y;
		double p = ((1-e)*(c-a)-(d-b)*(1-f))/((d-b)*(d-b)+(c-a)*(c-a));
		if(p>0&&p<1) {
			double g = a+(c-a)*p;
			double h = b+(d-b)*p;
			return Math.sqrt((e-g)*(e-g)+(f-h)*(f-h));
		}
		else return Math.sqrt(Math.min((e-a)*(e-a)+(f-b)*(f-b),(e-c)*(e-c)+(f-d)*(f-d)));
	}
}

class Point{
	double x,y;
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
}
