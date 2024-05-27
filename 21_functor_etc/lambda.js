
function foo(ftor) {
	// do something with ftor
	return ftor(1, 2);
}

function main() {
	var i = 0;
	foo(
		(a, b) => {
			i++;
			return a + b;
		}
	);
}