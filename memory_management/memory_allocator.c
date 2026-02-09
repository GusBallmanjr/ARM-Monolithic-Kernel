typedef struct pagetable {
  int* startPoint;
  int* endPoint;
} PageTable;

int brk(PageTable* pt, void* n) { 
  pt->endPoint = n;
  return 1;
}

int sbrk(PageTable* pt, int n) { 
  pt->endPoint = pt->endPoint + n; 
  return 1;
}

int mnap() { return 0; }

int munmap() { return 0; }

int mlock() { return 0; }

int munlock() { return 0; }
