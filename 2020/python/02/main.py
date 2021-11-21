class PasswordValidator(object):

    def __init__(self, data):
        self.passwords = []
        self.valid_passwords = []

        for row in data:
            self.passwords.append(row)
        data.close()

    def validate(self):
        for row in self.passwords:
          policy = self.__get_policy(row)
          password = self.__get_password(row)
          # if policy matches password, add to `self.valid_passwords

    # Might not need this.
    # def valid_passwords(self):
        # return self.valid_passwords

    def __get_policy(self, row):
        # IMPLEMENT 
        print('TBD')

    def __get_password(self, row):
        print('TBD')
