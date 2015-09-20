/*
05 Longest Palindromic Substring.c
https://oj.leetcode.com/problems/longest-palindromic-substring/
*/
var preWork = function(src){
	if(src.length === 0){
		return '^$';
	}
	var res = new Array((src.length << 1) + 3);
	res[0] = '^';
	for(var i = 0;i < src.length;i++){
		res[(i << 1) + 1] = '#';
		res[(i << 1) + 2] = src.charAt(i);
	}
	res[(src.length << 1) + 1] = '#';
	res[(src.length << 1) + 2] = '$';
	return res.join('');
};

var longestPalindrome = function(src){
	var i = 0;
	var T = preWork(src);
	var P = new Array(T.length); // palindromic length
	for(i = 0;i<T.length;i++){
		P[i] = 0;
	}

	var C = 0; // center
	var R = 0; // radius from 0
	var j = -1; // mirror

	var rc = 0; // result center
	var rl = 0; // result length

	for(i = 1;i < T.length - 1;i++){
		j = 2 * C  - i;

		// if i is in (C,R)
		if(R > i){
			P[i] = Math.min(R - i, P[j]);
		}

		// expand from i
		while(T[i + 1 + P[i]] === T[i - 1 - P[i]]){
			P[i]++;
		}

        // re-center
		if(R < i + P[i]){
			R = i + P[i];
			C = i;
		}

        // update result
		if(rl < P[i])
        {
        	rl = P[i];
        	rc = i; 
        }
	}
	return src.slice((rc - 1 - rl) / 2, (rc - 1 + rl) / 2);
};
