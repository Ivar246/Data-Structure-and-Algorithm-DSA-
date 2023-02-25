class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor(head = null) {
    this.head = head;
  }

  get size() {
    let node = this.head;
    let i = 0;
    while (node) {
      i++;
      node = node.next;
    }
    return i;
  }

  append(newNode) {
    let node = this.head;
    if (!node) {
      this.head = newNode;
      return;
    }
    while (node.next) {
      node = node.next;
    }
    node.next = newNode;
  }

  insertAtBegining(data) {
    let newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
  }

  reverseNode() {
    let prevNode = null;
    let currentNode = this.head;
    if (!currentNode) return;
    let nextNode;
    while (currentNode) {
      nextNode = currentNode.next;
      currentNode.next = prevNode;
      prevNode = currentNode;
      currentNode = nextNode;
    }
    this.head = prevNode;
  }

  insertAtIndex(index, newNode) {
    let currentNode = this.head;
    let c = 0;
    while (currentNode) {
      if (c + 1 === index) {
        let temp = currentNode.next;
        currentNode.next = newNode;
        newNode.next = temp;
        return;
      }
      currentNode = currentNode.next;
      c++;
    }
  }

  deleteAtIndex(index) {
    let currentNode = this.head;
    let c = 0;
    console.log("size", this.size);
    console.log(index, this.size);
    if (index > this.size - 1) {
      console.log("index out of range");
      return;
    }
    while (currentNode) {
      if (c + 1 === index) {
        currentNode.next = currentNode.next.next;
        return;
      }
      currentNode = currentNode.next;
      c++;
    }
  }

  print() {
    let node = this.head;
    while (node) {
      console.log(node.data);
      node = node.next;
    }
  }
}

let list = new LinkedList();
list.append(new Node(5));
list.append(new Node(16));
list.append(new Node(12));
list.append(new Node(13));
list.append(new Node(14));
list.insertAtBegining(4);
list.insertAtIndex(2, new Node(32));
list.deleteAtIndex(6);
list.deleteAtIndex(6);
list.print();
console.log(list.size);
