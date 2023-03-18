//  if(argc > 2){
    
//     string prefix;
//     vector<Movies> bestMovies;
//     vector<string> foundPrefixes;

//     // Run for each prefix argument given
//     for(int i=2;i<argc;i++){
//       vector<Movies> samePrefixMovie;
//       int left=0;
//       int right=movieList.size()-1;
//       int middle=0;
//       bool same=true;
//       prefix=argv[i];

//       // For each prefix, find all movies that have that prefix and store them in an appropriate data structure
//       // Binary search for middle
//       while(left<=right){ 
//         middle = (left + (right))/2;
//         for(int k=0;k<prefix.size();k++){
//           if(movieList.at(middle).movieName.at(k)!=prefix.at(k)){
//             same=false;
//             break;
//           }
//         }        
//         if(same){
//           samePrefixMovie.push_back(movieList.at(middle));
//           break;
//         }
//         if(movieList.at(middle).movieName < argv[i]){
//           left=middle+1;
//         }
//         else{
//           right=middle-1;
//         }
//         same=true;
//       }
      
//       // If no movie with that prefix exists print the following message
//       if(samePrefixMovie.size()==0){
//         cout<<"No movies found with prefix "<<prefix<<endl<<endl;
//         break;
//       }

//       // Add prefixes that have matches into a list
//       foundPrefixes.push_back(prefix);

//       // Linear search up from middle
//       for(int k=middle-1;k>0;k--){
//         for(int j=0;j<prefix.size();j++){
//           if(movieList.at(k).movieName.at(j)!=prefix.at(j)){
//             same=false;
//             break;
//           }
//         }
//         if(same){
//           samePrefixMovie.push_back(movieList.at(k));
//         }
//         same = true;
//       }

//       // Linear search down from middle
//       for(int k=middle+1;k<movieList.size();k++){
//         for(int j=0;j<prefix.size();j++){
//           if(movieList.at(k).movieName.at(j)!=prefix.at(j)){
//             same=false;
//             break;
//           }
//         }
//         if(same){
//           samePrefixMovie.push_back(movieList.at(k));
//         }
//         same = true;
//       }
      
//       // Sort based on rating after compiling all matching prefixes into a list
//       sort(samePrefixMovie.begin(),samePrefixMovie.end(),compareRating);
      
//       // Print movies that match with prefix
//       for (int k=0;k<samePrefixMovie.size();k++){
//         cout << samePrefixMovie.at(k).movieName << ", " <<  std::fixed << std::setprecision(1) << samePrefixMovie.at(k).movieRating << endl;
//       }

//       // Add highest rating movies into a list
//       if(!samePrefixMovie.empty()){
//         bestMovies.push_back(samePrefixMovie.at(0));
//       }

//       cout << endl;
      
      
//     }
//     //  For each prefix,
//     //  Print the highest rated movie with that prefix if it exists.
//     for(int i=0;i<foundPrefixes.size();i++){
//       cout << "Best movie with prefix "<<foundPrefixes.at(i)<<" is: " << bestMovies.at(i).movieName <<" with rating " << std::fixed << std::setprecision(1) <<bestMovies.at(i).movieRating<< endl;
//     }

//     return 0;
//   }