package BOJ16565;

import java.util.Scanner;

/*
 * BOJ 16565 N포커
 * 딜러와 플레이어의 1:1게임을 만든다.
 * 플레이어가 52장의 트럼프카드에서 N장의 카드를 뽑는다.
 * 뽑은 카드로 "포카드" 를 완성하면 플레이어의 승리.
 * N을 입력받을때, 플레이어가 이기는 경우의 수를 출력하라.
 *
 * 풀이
 * 52CN 를 했는데, 그 중에, 같은 숫자 4개가 있어야한다.
 * 일단 N이 4보다 작다면 경우의 수는 0
 * 4개를 뽑는다면, 1~13까지 경우의 수는 13
 * 5개를 뽑는다면 어떨까? 일단 4개를 뽑고, 나머지에서 1개를 더 뽑는다.
 * 즉          13* 48C1 = 13 * (48 ) / (1)
 * 6개를뽑는다면? 13* 48C2 = 13 * (48 * 47) / (1*2)
 * 7개를뽑는다면? 13* 48C3 = 13 * (48 * 47 * 46) / (1* 2 * 3)
 * 아하 DP구나!
 * 하지만 만약 8개를 뽑는다면 어떨까? 이때는 조금 달라진다.
 * 왜냐하면, 포카드가 중복될 수 있기 때문이다. 
 * 1111 과 2222 를 뽑는 경우와 2222와 1111를 뽑는건 같은 경우이다.
 * 4개의 정답을 뽑아두고, 나머지 4장을 고르지만 각 중복 케이스를 빼줘야 한다.
 * 13* 48C4 -44C0*(78=0+1+2+3+4+5+6+7+8+9+10+11+12)
 * 이쯤와서 생각을 달리 해보자.
 * 전체 52CN 에서, 하나도 포카드가 없는 경우를 빼주면 어떨까
 * 뽑는 장수를 기준으로하지 말고, 포카드의 수를 기준으로 해보자
 * 포카드의 최소 갯수는 0개.. 최대갯수는 13개
 * 포카드가 0개인 경우는 고려하지 않는다. 원하는 경우의수가 없기때문
 * 포카드가 1개인 경우의 수
 * 13개의 숫자중 1개를 고름 = 13C1 =  13
 * 나머지 48장중에서 N-4장 고름 48C(N-4)
 * 13C1*48C(N-4)
 * 포카드가 2개인 경우의 수
 * 13개의 숫자중 2개를 고름 = 13C2 = 13* 12 / 2
 * 나머지 44장중에서 N-8장 고름 48C(N-8)
 * 13C2*48C(N-8)
 * 포카드가 k개라면?
 * 13Ck*(52-4k)C(N-4k)
 * 다 합산하면 모든 경우의 수를 알 수 있다.
 * 
 * factorial, reversefactorial을 미리 계산해두자
 * 
 * 
 */
public class Main {
	
	static Scanner sc;
	static long[] dp;
	static long[] factorial;
	static long[] reverseFactorial;
	static int N,sum;
	static final int  MOD = 10007;
	public static void main(String[] args) {
		input();
		init();
		for(int fourCardCnt = 1; fourCardCnt<=13;fourCardCnt++) {
			int usedCard = fourCardCnt<<2;
			if(usedCard>N) break;
			long selectFourCard = comb(13,fourCardCnt);
			long selectOtherCard = comb(52-usedCard,N-usedCard);
			sum+= selectFourCard*selectOtherCard%MOD;
		}
		
		System.out.println(sum);
	}
	static void input() {
		sc = new Scanner(System.in);
		N = sc.nextInt();
	}
	static void init() {
		dp = new long[53];
		factorial = new long[53];
		reverseFactorial = new long[53];
		factorial[1] = 1;
		reverseFactorial[52] = 52;
		
		for(int i = 2; i<=52; i++) {
			factorial[i] = (factorial[i-1] *i)%MOD;
			int reverse = 53-i;
			reverseFactorial[reverse] = (reverseFactorial[reverse+1]* reverse)%MOD;
		}
		
	}
	
	static long comb(int n, int r) {
		return (reverseFactorial[n] / factorial[r]) %MOD;
	}
	
}
