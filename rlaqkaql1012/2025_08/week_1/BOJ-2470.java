package BOJ2470;

/*
 * BOJ 2470 두 용액
 * 알칼리성 -1~-10억
 * 산성 1~10억
 * 두 용액을 섞어서 0에 가까운 용액을 만든다.
 * 
 * 두 수의 합의 최소화
 * 이분탐색
 * 정렬한다.
 * l = X1, r= Xn m =(l+r)/2
 * 만약 합이 0보다 작다면, 용액의 산성을 키워야하므로 l=m+1
 * 만약 합이 0보다 크다면, 용액의 알칼리를 키워야하므로 r=m-1
 * 만약 합이 0이라면 return
 * 
 * 도 되는데 걍 투포인터로품
 * 정렬한다.
 * l = X1, r= Xn
 * 만약 합이 0보다 작다면, 용액의 산성을 키워야하므로 l++
 * 만약 합이 0보다 크다면, 용액의 알칼리를 키워야하므로 r--
 * 만약 합이 0이라면 return
 */

import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int N;
	static int[] solutions;
	public static void main(String[] args) throws Exception{
		br = new BufferedReader(new InputStreamReader(System.in));
		sb = new StringBuilder();
		N = Integer.parseInt(br.readLine());
		solutions = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < N ; i ++) {
			solutions[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(solutions);
		
		twoPointer();
	}
	
	
	static void twoPointer() {
		int l = 0;
		int r = N-1;
		long minValue = Long.MAX_VALUE;
		int ansL=l;
		int ansR=r;
		while(l<r) {
		

			long acid = solutions[l] + solutions[r];
//			System.out.println(String.format("%d %d %d", l,r,acid));
			
			if(minValue > Math.abs(acid)) {
				ansL = l;
				ansR = r;
				minValue= Math.abs(acid);
			}
			if(acid==0) break;
			if(acid>0) {
				r--;
			}
			else {
				l++;
			}
			
		}
		int min = (solutions[ansL]<solutions[ansR])?solutions[ansL]:solutions[ansR];
		int max = (solutions[ansL]<solutions[ansR])?solutions[ansR]:solutions[ansL];
		sb.append(min).append(" ").append(max);
		System.out.println(sb);
	}
	
}
