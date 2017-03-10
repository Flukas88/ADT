node (''){

stage 'Compile'
    sh 'cd list && make'
  
  
  
stage 'Test'
  
  dir('list') {
    sh './list.o'
  }
  

}
