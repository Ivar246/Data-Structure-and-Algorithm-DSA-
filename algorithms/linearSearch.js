const arr = [35, 50, 69, 87, 76, 24, 14];
let searchedElement = 69;

const linearSearch = (searchedElement) => {
  for (let el of arr) {
    if (el === searchedElement) return arr.indexof(el);
    else return null;
  }
};

if (!linearSearch(searchedElement)) {
  console.log("Not found");
} else {
  console.log(`found at index: ${linearSearch(searchedElement)}`);
}
