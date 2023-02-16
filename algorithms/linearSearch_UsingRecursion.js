const arr = [2, 3, 4, 9, 6, 7];
let searchedEl = 3;

function linearSearch(i, arr, el) {
  if (i >= arr.length) return -1;
  if (arr[i] === el) return i;
  linearSearch(i + 1, arr, el);
}

const index = linearSearch(0, arr, searchedEl);

if (index === -1) {
  console.log("not found");
} else {
  console.log(`found at index:${index}`);
}
