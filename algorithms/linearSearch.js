const arr = [35, 50, 69, 87, 76, 24, 14];
let searchedElement = 69;

function linearSearch(searchedElement, arr) {
  for (let el of arr) {
    if (el === searchedElement) return arr.indexOf(el);
  }
  return -1;
}

const index = linearSearch(searchedElement, arr);

if (index === -1) {
  console.log("Not found");
} else {
  console.log(`found at index: ${index}`);
}
