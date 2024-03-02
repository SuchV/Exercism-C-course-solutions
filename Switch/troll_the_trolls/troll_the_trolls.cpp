namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus {
        troll,
        guest,
        user,
        mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum class Action {
        read,
        write,
        remove
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer) {
        if(poster == AccountStatus::troll && viewer == AccountStatus::troll) return true;
        if(poster == AccountStatus::troll || viewer == AccountStatus::troll) return false;
        return true;
    }

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
    bool permission_check(Action userAction, AccountStatus status) {
        switch (status) {
            case AccountStatus::guest:
                switch (userAction) {
                    case Action::read: return 1;
                    default: return 0;
                }
            case AccountStatus::troll:
            case AccountStatus::user:
                switch (userAction){
                    case Action::read:
                    case Action::write: return 1;
                    default: return 0;
                }
            case AccountStatus::mod:
                default: return 1;
        }
        return 0;
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus account1, AccountStatus account2) {
        switch (account1) {
            case AccountStatus::troll:
                switch (account2) {
                    case AccountStatus::troll: return 1;
                    default: return 0;
                }
            case AccountStatus::guest:
                return 0;
            default:
                switch (account2) {
                    case AccountStatus::troll: return 0;
                    case AccountStatus::guest: return 0;
                    default: return 1;
                }
        }
        return 0;
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus account1, AccountStatus account2) {
        switch (account1) {
            case AccountStatus::mod:
                switch (account2) {
                    case AccountStatus::mod: return 0;
                    default: return 1;
                }
            case AccountStatus::user:
                switch (account2) {
                    case AccountStatus::mod:
                    case AccountStatus::user: return 0;
                    default: return 1;
                }
            case AccountStatus::guest:
                switch (account2) {
                    case AccountStatus::troll: return 1;
                    default: return 0;
                }
            case AccountStatus::troll:
                return 0;
        }
        return 0;
    } 
}  // namespace hellmath