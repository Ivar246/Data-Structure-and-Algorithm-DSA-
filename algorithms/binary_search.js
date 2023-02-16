const arr = [56, 71, 46, 93, 85];
const sorted = arr.sort((a, b) => a - b);
const target = 71;

function binarySearch(target, low, high, arr) {
  while (low <= high) {
    let mid = Math.floor((high + low) / 2);
    if (target === arr[mid]) return mid;
    else if (target < arr[mid]) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
}

const index = binarySearch(target, 0, sorted.length - 1, sorted);
if (index === -1) console.log("not found");
else console.log(`found at index:${index}`);
