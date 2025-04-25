pipeline{
    agent{
        docker{
            image 'node:18.17.1-alpine3.18'
            args '-u root'
        }
    }

    parameters{
         booleanParam(name: 'RELEASE', defaultValue: false, description: 'Set to true for a release build')
    }

    stages{
        stage('Build'){
            steps{
                echo 'Building...'
                
                sh 'echo "--- Running as User ---"'
                sh 'whoami' // Should confirm 'root'
                sh 'echo "--- Current Directory ---"'
                sh 'pwd'
                sh 'echo "--- Environment Variables (Sorted) ---"'
                sh 'env | sort' // Check PATH and other variables here
                sh 'echo "--- Specific PATH Check ---"'
                sh 'echo $PATH'

                // 2. Check the suspected location directly
                sh 'echo "--- Check /usr/bin directly ---"'
                sh 'ls -l /usr/bin/make || echo "/usr/bin/make NOT FOUND by ls"'

                // 3. Attempt to run 'which' via different shells (if available)
                sh 'echo "--- Check which via sh ---"'
                sh 'which make || echo "make not found by which (sh)"'
                sh 'echo "--- Check which via bash (if installed) ---"'
                sh 'bash -c "which make" || echo "make not found by which (bash) or bash not found"'

                // 4. Attempt to run make using the full path
                sh 'echo "--- Attempt execution via full path ---"'
                sh '/usr/bin/make --version || echo "/usr/bin/make --version FAILED"'

                // 5. The command that originally failed
                sh 'echo "--- Attempt original make clean ---"'

                sh 'make clean'
                sh "RELEASE=${params.RELEASE} make all"
                echo "Linux Native build complete."
            }
        }
        stage('Test'){
            steps{
                echo 'Testing...'
                sh './app test test test waaaaaaa'
            }
        }
        stage('Deploy'){
            steps{
                echo 'Deploying...'
            }
        }
    }
}