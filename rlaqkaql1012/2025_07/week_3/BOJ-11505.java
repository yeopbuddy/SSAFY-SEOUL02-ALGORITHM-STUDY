package BOJ11505;

import java.io.*;
import java.util.*;

/*
 * BOJ 11505 구간 곱 구하기
 * 정수 수열 Xn 에서 Xa부터 Xb까지의 곱을 구하라.
 * Xn의 내부에서 수의 변경이 빈번하게 일어난다.
 * 
 * 풀이
 * 세그먼트트리
 * Tree[N+i]에 Xi를 저장
 * Tree[N+i] * Tree[N+i+1] 의 값을 Tree[(N+1)/2]에 저장
 * 
 */

public class Main {
	
	static BufferedReader br;
	static StringTokenizer st;
	static StringBuilder sb;
	static int N,M,K; //N 수의 수 M 변경횟수 K구간곱 횟수
	static int[] Tree;
	static int startPoint;
	public static void main(String[] args) throws Exception{
		sb = new StringBuilder();
		br = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		for(startPoint=1; startPoint<=(N<<1);startPoint<<=1) {}

		Tree = new int[startPoint];
		startPoint >>=1;
		
		Arrays.fill(Tree, 1);
		for(int line = 0; line<N; line++) {
			Tree[startPoint+line] = Integer.parseInt(br.readLine());
		}
		
		for(int idx = startPoint; idx>1;idx>>=1) {
			for(int col = idx; col<idx<<1;col+=2) {
				Tree[col>>1] = Tree[col] * Tree[col+1];
			}
		}

		
		for(int line = 0;line<M+K;line++) {
			st = new StringTokenizer(br.readLine());
			int command = Integer.parseInt(st.nextToken());
			int first = Integer.parseInt(st.nextToken());
			int second = Integer.parseInt(st.nextToken());
			if(command ==1) {
				change(first,second); //first번째 숫자를 second로 변경
			}
			if(command ==2) {
				multi(first,second); //first부터 second까지 구간 곱 구하기
			}
		}
		System.out.println(sb.toString());
	}
	
	static void change(int first, int second) {
		int idx = startPoint+first-1;
		Tree[idx] =second;
		while(idx>1) {
			int nxt = idx>>1;
			if((idx&1) ==0) {
				Tree[nxt] = Tree[idx]*Tree[idx+1];
			}
			else {
				Tree[nxt] = Tree[idx-1]*Tree[idx];
			}
			idx = nxt;
		}
//		System.out.println(Arrays.toString(Tree));
	}
	
	static void multi(int first, int second) {
		int left = Math.min(first, second)+startPoint-1;
		int right = Math.max(first, second)+startPoint-1;
		long result = 1;
//		System.out.println(left+","+right+","+result);
		while(left<right) {
			if((left&1)==1) {
				result*= Tree[left];
				left++;
			}
			if((right&1)==0) {
				result*= Tree[right];
				right--;
			}
			left>>=1;
			right>>=1;
//			System.out.println(left+","+right+","+result);
		}
		result*=Tree[left];
		sb.append(result).append("\n");
	}
	
	
}
