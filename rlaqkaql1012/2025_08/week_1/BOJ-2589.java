package BOJ2589;

/*
 * 보물섬
 * 보물섬지도는 직사각형이며 n*m칸이다.
 * 각 칸은 육지(L) 혹은 바다(W)이다.  상하좌우로 이웃한 육지로만 이동가능
 * 한칸이동 = 1시간 , 보물은 서로 최단 거리로 이동하기 가장 먼 육지 두곳에 놓여있다.
 * 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면 같은 곳 두번 못간다.
 * 보물간의 이동 시간을 구하라.
 * 
 * 풀이
 * 가장 BFS 거리가 먼 두 육지의 거리를 구하는 문제이다.
 * 플로이드 워셜로 모든 칸 to 모든 칸의 거리를 구한다.
 * 가장 큰 값을 반환한다.
 * 걍 모든점에서 BFS를 돌려볼까..?
 * => 이게 되네..
 * 
 * BOJ 1위에게 배워온 개선포인트 :
 * 어차피 최장거리는 섬내에서 가장자리와 가장자리이다.
 * 즉 모든점에서 BFS 돌 필요 없이,섬의 가장자리를 찾아서, 그곳에서만 BFS를 돈다.
 * 
 */
import java.io.*;
import java.util.*;
public class Main {
	
	static StringTokenizer st;
	static BufferedReader br;
	static char[][] map;
	static boolean[][] visited1, visited2;
	static int[] dc = {0,0,-1,1};
	static int[] dr = {-1,1,0,0};
	static int rowSize,colSize,maxDistance;
	static LinkedList<int[]> q1,q2;
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		rowSize = Integer.parseInt(st.nextToken());
		colSize = Integer.parseInt(st.nextToken());
		map = new char[rowSize][colSize];
		
		for(int row = 0; row<rowSize;row++) {
			map[row] = br.readLine().toCharArray();	
		}
		q1 = new LinkedList<int[]>();
		q2 = new LinkedList<int[]>();
		visited1 = new boolean[rowSize][colSize];
		for(int row=0;row<rowSize;row++) {
			for(int col=0; col<colSize;col++) {
				if(map[row][col]=='W'||visited1[row][col]) {
					continue;
				}
				visited1[row][col] =true;
				//섬의 가장 자리를 찾고,
				dfs(row,col);
				visited2=new boolean[rowSize][colSize];
				//그곳에서부터 BFS
				while(!q1.isEmpty()) {
					q2.add(q1.poll());
					bfs();
				}
				
			}
		}
		
		System.out.println(maxDistance);
		
	}
	static void dfs(int row, int col) {

		boolean isEdge = true;
		
		for(int d = 0; d<4; d++) {
			int nr = row+dr[d];
			int nc = col+dc[d];
			if(nr<0||nc<0||nr>=rowSize||nr>=colSize||visited1[nr][nc]
					||map[nr][nc]!='L')continue;
			visited1[nr][nc] = true;
			isEdge = false;
			dfs(nr,nc);
		}
		
		if(isEdge) {
			q1.add(new int[] {row,col,0});
		}
		
	}
	
	static void bfs() {
		visited2 = new boolean[rowSize][colSize];
		while(!q2.isEmpty()) {
			int[] cur =q2.poll();
			int curRow = cur[0];
			int curCol = cur[1];
			int curDistance = cur[2];
			for(int d = 0; d<4;d++) {
				int nxtRow = curRow+dr[d];
				int nxtCol = curCol+dc[d];
				int nxtDistance = curDistance+1;
				if(nxtRow<0||nxtCol<0||nxtRow>=rowSize||nxtCol>=colSize||visited2[nxtRow][nxtCol]
						||map[nxtRow][nxtCol]!='L')continue;
				visited2[nxtRow][nxtCol]= true;
				
				q2.add(new int[] {nxtRow,nxtCol,nxtDistance});
			}
			if(q2.isEmpty()) {
				maxDistance = Math.max(curDistance, maxDistance);
			}
		}
		
//		System.out.println(String.format("%d , %d => %d", row,col,maxDistance));
	
	}
}
