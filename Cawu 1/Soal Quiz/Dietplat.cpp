#include <stdio.h>

int ans = 0;

void dietPlan(int days, int cm, int cb, int sd[], int now){
	if(now == days) return;
	else{
		// SUSU
		if(cm >= 0){
			if(cm == 0 && now > ans) ans = now;
			dietPlan(days, cm-sd[now], cb, sd, now+1);
		}
		// BISKUIT
		if(cb > 0){
			if(cm == 0 && now > ans) ans = now; // artinya akan dicataan saat susu HABIS
			dietPlan(days, cm, cb-1, sd, now+1);
		}
	}
}

int main(){
	int days, totalMilk, totalBiscuit;
	int susuDays[101];
	scanf("%d %d %d", &days, &totalMilk, &totalBiscuit);
	for(int i = 0; i < days; i++){
		scanf("%d", &susuDays[i]);
	}
	
	dietPlan(days, totalMilk, totalBiscuit, susuDays, 0);
	printf("%d\n", ans);
	// printf("%d\n", dietPlan(days, totalMilk, totalBiscuit, susuDays, 0));
	
	return 0;
}