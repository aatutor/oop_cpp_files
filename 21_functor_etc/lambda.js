
function foo(ftor) {
	// do something with ftor
	return ftor(1, 2);
}

function main() {
	var i = 0;
	var a = foo(
		(a, b) => {
			i++;
			return a + b;
		}
	);
	console.log(a + ' ' + i);
}

main();
